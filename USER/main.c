#include "key.h"
#include "delay.h"
#include "usart.h"
#include "bujin.h"
#include "timer.h" 
//#include  "1602.h"
#include "tar.h"
#include "led.h"
#include "uart2.h"
#include "exti.h"


/**
	 ����2		PA9 PA10
	 ����		PC5,PA0 ,PA15
	 ���������	PC6,7,8,9
	 �ⲿ�ж�   PC0
	 ADC        PA1
**/



void System_init()
{
	NVIC_Configuration();
	LED_Init();	
	delay_init();				
	uart_init(9600);			 
	uart2_init(115200);			//����2��ʼ��
	KEY_Init();					//������ʼ��
	bujin_init();	 			//���������ʼ��
	exti_init();				//�ⲿ�жϳ�ʼ��
	TIM3_Int_Init(9999,7200);	//��ʱ��3��ʼ��1s
}

 int main(void)
 {	
	u8  key_value = 0;

	System_init();
	
	while(key_value == 0)
	{
		key_value = KEY_Scan(0);
		delay_ms(10);
	}
	//TIM_Cmd(TIM3,ENABLE);
	switch(key_value)
	{
		case KEY0_PRES:		 tar1();	break;
		case KEY1_PRES:		 tar2();	break;	
		case WKUP_PRES:		 tar3();	break;
		default: break;
	}
	
	while(1);
	return 0;
 }
  




