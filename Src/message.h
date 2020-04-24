#ifndef MESSAGE_H
#define MESSAGE_H

//開始從usart讀資料
void MessageStartReceive(void);
//停止從usart讀資料
void MessageStopReceive(void);

//usart會把收到的char放進g_RxBuffer
//MessageGetCmd會判斷g_RxBuffer裡是否包含完整的command
//如果是完整的command就把整個command放到buffer中，並回傳command size
//如果command不完整就不改變buffer內容，並回傳0
//如果command size > maxSize也不改變buffer內容並回傳0
unsigned short MessageGetCmd(char* buffer,unsigned short maxSize);

//將長度為length的buffer資料放進g_TxBuffer
//讓usart將內容傳出去
void MessageSendData(char* buffer,unsigned short length);

#endif
