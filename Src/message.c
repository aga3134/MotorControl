#include "message.h"
#include "main.h"

FIFOBufferInstance g_TxBuffer;
FIFOBufferInstance g_RxBuffer;

enum MessageState{
	HEADER,
	CMD,
	ARG_NUM,
	ARGS,
	CHECKSUM
};

static unsigned char g_TxLock = 0;
static unsigned char g_InData;
static unsigned char g_OutData;

void MessageStartReceive(){
	HAL_UART_Receive_IT(g_HR.pUART1,&g_InData,1);
}

void MessageStopReceive(){
	HAL_UART_AbortReceive_IT(g_HR.pUART1);
}

unsigned short MessageGetCmd(char* buffer, unsigned short maxSize){
	int i=0;
	int size = FIFOBufferGetDataSize(&g_RxBuffer);
	int len = maxSize<size?maxSize:size;
	enum MessageState state = HEADER;
	unsigned char d, sum = 0, valid = 0;
	unsigned short argNum = 0,start = 0, end = 0;
	
	//�P�_�O�_������command
	for(i=0;i<len && !valid;i++){
		FIFOBufferPeekData(&g_RxBuffer,&d,i);
		switch(state){
			case HEADER:
				if(d == 0xFE){
					state = CMD;
					start = i;
					end = i;
					sum = d;
				}
				break;
			case CMD:
				state = ARG_NUM;
				end++;
				sum += d;
				break;
			case ARG_NUM:
				argNum = d;
				end++;
				sum += d;
				if(argNum == 0) state = CHECKSUM;
				else state = ARGS;
				break;
			case ARGS:
				end++;
				sum += d;
				if(end == start+2+argNum) state = CHECKSUM;
				break;
			case CHECKSUM:
				end++;
				if(sum == d){
					valid = 1;
				}
				break;
		}
	}
	//�h��header���e�����
	if(state == HEADER) start = len;	//Ū��᳣̫�٨SŪ��header�A�����M��
	FIFOBufferClear(&g_RxBuffer,start);
	
	if(state == CHECKSUM){	//�wŪ�짹��command
		unsigned short cmdSize = end-start+1;
		if(valid){	//checksum����ok
			FIFOBufferGetData(&g_RxBuffer,(unsigned char*)buffer,cmdSize);
			return cmdSize;
		}
		else{	//checksum���祢�ѡA�ᱼ��command
			FIFOBufferClear(&g_RxBuffer,cmdSize);
			return 0;
		}
	}
	return 0;	//command������A�U���AŪ
}

void MessageSendData(char* buffer,unsigned short length){
	//put data into g_TxBuffer
	unsigned short num = FIFOBufferPutData(&g_TxBuffer,(unsigned char*)buffer,length);
	if(num == 0) return;	//���F
	
	//�Y�S�b�ǿ�N�}�l��
	if(!g_TxLock){
		if(FIFOBufferGetData(&g_TxBuffer,&g_OutData,1)){
			g_TxLock = 1;
			HAL_UART_Transmit_IT(g_HR.pUART1, &g_OutData,1);
		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle){
	//�NŪ�쪺��Ʀs��g_InData
  FIFOBufferPutData(&g_RxBuffer,&g_InData,1);
	//�~�򵥤U�@�����
	HAL_UART_Receive_IT(g_HR.pUART1,&g_InData,1);
	
	//echo�^�h
	//HAL_UART_Transmit_IT(&huart1, &g_InData,1);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle){
	//�p�Gg_TxBuffer����ƴN�~��e�U�@�����
  if(FIFOBufferGetData(&g_TxBuffer,&g_OutData,1)){
		HAL_UART_Transmit_IT(g_HR.pUART1, &g_OutData,1);
	}
	else g_TxLock = 0;
}
