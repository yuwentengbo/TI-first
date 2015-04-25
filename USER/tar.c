#include "tar.h"
#include "led.h"
#include "delay.h"
#include "bujin.h"
#include "math.h"
#include "key.h"
#include "usart.h"
#include "encoder.h"


float tar1()
{
	u8  i=0,key_value = 0,moter1_i = 0,moter2_i=0;
	float bujin_cnt = 0;
	float angle=0,angle1 = 0;

		
	while(key_value == 0)
	{
		key_value = KEY_Scan(0);
		delay_ms(10);
	}
	
	delay_ms(1000);
	while(1)
	{
		angle= encoder_get_angle();
		while(1)
		{
			angle= encoder_get_angle();
			
			if(-25<angle&&angle<-17)			//Ç°À­
			{
				Moter_Go_ahead(35,moter1_i=(moter1_i+1)%8);
				bujin_cnt += 1;
			}
			else if(-17<angle && angle< -12)
			{
				Moter_Go_ahead(35,moter1_i=(moter1_i+1)%8);
				bujin_cnt += 1;
				delay_ms(150);
			}
			else 
			{
				delay_ms(2000);
				while(1)
				{
					angle= encoder_get_angle();
					if(angle >-5 && angle < 5)		
					{
						LED1 = 0;
						return bujin_cnt;
					}
					Moter_Go_ahead(40,moter1_i=(moter1_i+1)%8);
					bujin_cnt += 1;
					delay_ms(4000);
				}
			}
		}
	}
}


