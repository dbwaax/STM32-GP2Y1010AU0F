#include "stm32f10x.h"
unsigned int dbw_Get_ESP8266_Cmd(unsigned char number,unsigned char * buff,unsigned int buff_size);
unsigned char dbw_Init_Frame(unsigned char cmd_id,char * data,unsigned int data_size,unsigned char * frame_buff,unsigned int frame_size);
void dbw_init_ESP8266(unsigned int step,unsigned char * buff);
void sendString(USART_TypeDef *USARTx, char *str);
void sendByte(USART_TypeDef *USARTx, u16 byte);
