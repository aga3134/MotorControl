#ifndef MESSAGE_H
#define MESSAGE_H

//�}�l�qusartŪ���
void MessageStartReceive(void);
//����qusartŪ���
void MessageStopReceive(void);

//usart�|�⦬�쪺char��ig_RxBuffer
//MessageGetCmd�|�P�_g_RxBuffer�̬O�_�]�t���㪺command
//�p�G�O���㪺command�N����command���buffer���A�æ^��command size
//�p�Gcommand������N������buffer���e�A�æ^��0
//�p�Gcommand size > maxSize�]������buffer���e�æ^��0
unsigned short MessageGetCmd(char* buffer,unsigned short maxSize);

//�N���׬�length��buffer��Ʃ�ig_TxBuffer
//��usart�N���e�ǥX�h
void MessageSendData(char* buffer,unsigned short length);

#endif
