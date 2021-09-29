#define data_Frame_Header 0x24
#define data_Frame_Tail 0x23
#include "HardWare_Cmd.h"      //keil5中加入include路径中便可以直接引用#include"HardWare_Cmd.h"
#include "string.h"
#include "stm32f10x.h"
struct dbw_Frame_init
{
	unsigned char header;
	unsigned char cmd_id;
	unsigned char block[2];
	unsigned int frame_size;
	char data[1024];     				//包含帧尾部
}data_frame;
unsigned int dbw_Get_ESP8266_Cmd(unsigned char number,unsigned char * buff,unsigned int buff_size)//Input number to cmd
{
	//number 表示第几条指令
	//buff 代表主函数用来接收命令的缓冲区
	//buff_size 代表缓冲区长度

	unsigned char point = dbw_Cmd_Table_Offset[number];
	unsigned char i = 0;
	unsigned int counter = 0;   //命令长度计数器
	unsigned char temp[173] = {0}; //命令临时缓冲区
	while(dbw_Esp8266_Cmd_Table[point]!=0x0d)
	{
		temp[counter] = dbw_Esp8266_Cmd_Table[point];
		counter++;
		point++;
	}
	temp[counter] = 0x0d;
	if(counter+2 <= buff_size)
	{
		while(temp[i]!=0x0d)
		{
			*(buff+i) = temp[i];
			i++;
		}
		if(number!=6)
		{
			*(buff+i++) = 0x0d;
			*(buff+i++) = 0x0a;
		}
		return counter+2;                //successful
	}
	else
	{
		return 0x02;               //failed
	}
}

void dbw_init_ESP8266(unsigned int step,unsigned char * buff)
{
	switch(step)
	{
		case 1:dbw_Get_ESP8266_Cmd(0,buff,60);break;
		case 2:dbw_Get_ESP8266_Cmd(2,buff,60);break;
		case 3:dbw_Get_ESP8266_Cmd(7,buff,60);break;
		case 4:dbw_Get_ESP8266_Cmd(4,buff,60);break;
	}	
}

unsigned char dbw_Init_Frame(unsigned char cmd_id,char * data,unsigned int data_size,char * frame_buff,unsigned int frame_size)
{
	unsigned int i = 0;
	data_frame.header = data_Frame_Header;
	data_frame.cmd_id = cmd_id;
	for(;i<2;i++)
	{
		data_frame.block[i] = 0xff;
	}
	i = 0;
	data_frame.frame_size = data_size+8;
	if(frame_size>=data_frame.frame_size&&data_frame.frame_size<sizeof(data_frame))
	{
		for(;i<data_size;i++)
		{
			data_frame.data[i] = *(data+i);
		}
		data_frame.data[strlen(data_frame.data)] = 0x23;
		memcpy(frame_buff,&data_frame,data_frame.frame_size);
	    return 0x01;
	}
	else
	{
		return 0x02;
	}
}
void sendByte(USART_TypeDef *USARTx, u16 byte)
{
    USART_SendData(USARTx, byte);                       
    while (!USART_GetFlagStatus(USARTx, USART_FLAG_TC));
    USART_ClearFlag(USARTx, USART_FLAG_TC);             
}

void sendString(USART_TypeDef *USARTx, char *str)
{
    while (*str)
    {
        sendByte(USARTx,*str++);
    }
}
