#include "key.h"
#include "delay.h"
#include "usart.h"
#include "bujin.h"
#include "tar.h"
#include "led.h"
#include "encoder.h"



/**
	 按键			PC5,PA0 ,PA15
	 步进电机1：	PA0,1,2,3
	 步进电机2：    PA4 5 6 7
	 PC 0 PC 1
	 PA8 PD2
	 
**/


void cal(float bujin_cnt);


void System_init()
{
	NVIC_Configuration();
	LED_Init();	
	delay_init();				
	uart_init(9600);			 
	KEY_Init();					//按键初始化
	bujin_init();	 			//步进电机初始化
	encoder_init();
}

 int main(void)
 {	
	u8  key_value = 0 ,i=0;
	float  angle,bujin_cnt = 0;
	int weight=0;
	System_init();
	 
	while(key_value == 0)
	{
		key_value = KEY_Scan(0);
		delay_ms(10);
	}
	
	while(1)
	{
		angle = encoder_get_angle();
		if(angle !=0 && angle < 3 && angle > -3)
		{
			LED0  = 0;
			break;
		}
		delay_ms(200);
	}
	
	
	bujin_cnt=tar1();	

	cal(bujin_cnt);
	return 0;
 }

 
 void cal(float bujin_cnt)
{
	float l1=0,l2=43,weight=0;
	l1=16.5 *bujin_cnt *0.9/360;
	weight=l1*0.37/43;
	usart1_send(weight);
}
  