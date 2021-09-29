#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "adc.h"
 void USART2_Send_Data(u8 *buf,u16 len)
 {
    u16 t;
        for(t=0;t<len;t++)        //??????
      {           
         while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);      
         USART_SendData(USART2,buf[t]);
     }     
     while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);          
 }
 int main(void)
 {
	float temp;
	float dust;
	u16 adcx;
	delay_init();
	PWM_init();
	uart_init(115200);
	Adc_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	while(1)
	{
		Wave_L;
		delay_us(280);
		adcx=Get_Adc(ADC_Channel_1);								//通道一获取 ad转换值
		delay_us(19);
		Wave_H;
		delay_us(9680);                             //产生周期位10ms 占空比0.032的方波 驱动程传感器
		temp=(float)adcx*(3.3/4096);								
		dust= (0.17*temp-0.1)*1000;;               // 电压AQI转换公式
		printf("V:%.3f\r\n",temp);
		printf("Dust:%.3f\r\n",dust);
		delay_ms(100);
		
	}
}

