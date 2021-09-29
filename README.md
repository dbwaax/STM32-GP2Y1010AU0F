# STM32-GP2Y1010AU0F
STM32-GP2Y1010AU0F   STM32实验PM2.5检测     
GP2Y1010AU0F红外粉尘传感器的主要原理是通过红外光在空气中的散射情况来确定出空气中的污染颗粒的浓度，其一共有六个引脚分别为：VCC、LED-VCC、D0、LED-GND、A0与VSS。    
其中，VCC位GP2Y1010AU0F的供电电压接5v即可。    
LED-VCC上了防止电压过高烧坏用来检测空气中颗粒物的红外灯，所以需要从VCC引入5v电压后接入150-200欧的电阻来减小压力。    
DO 是GP2Y1010AU0F的驱动脉冲输入引脚，需要用微机输入周期位10ms占空比位0.032的脉冲即可驱动。    
LED-GND位红外灯的地端，与VSS相接即可。    
	A0为检测到的空气中PM2.5值的模拟量，需要进行模数转好后按照一定公式计算即可得到当前空气中PM2.5值。    
	VSS接电源地即可。    


    
   
        
![image](https://github.com/dbwaax/STM32-GP2Y1010AU0F/blob/main/23.jpg)
