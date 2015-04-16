#include "bujin.h"
#include "delay.h"

/*
	���������ʼ��
	PC6,7,8,9
*/
void bujin_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
}

//ֹͣ
void Moter_Stop()
{
	PCout(6) = 0; PCout(7) = 0; PCout(8) = 0; PCout(9) = 0;
}


/*
PC67	һ��
PC89
������1.8��
speed  �ٶ� 
flag  ��ת��ת
ȫ��
*/
/*
void Moter_Go(u8 speed,u8 flag)		
{
	if(flag == 0)
	{
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);
		
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
	}
	else
	{
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
			
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);

		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
	}
}/*

	
/*
PC67	һ��
PC89
������0.9��
speed  �ٶ� 
flag  ��ת��ת
x	   ϸ�ֵ�ÿһ��
*/	

void Moter_Go(u8 speed,u8 flag,u8 x)		
{
	if(flag == 0)
	{
		switch(x)
		{
			case 0:	PCout(6) = 1; PCout(7) = 0; PCout(8) = 0; PCout(9) = 0;		break;
			case 1:	PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;		break;
			case 2:	PCout(6) = 0; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;		break;
			case 3:	PCout(6) = 0; PCout(7) = 1; PCout(8) = 1; PCout(9) = 0;		break;
			case 4:	PCout(6) = 0; PCout(7) = 1; PCout(8) = 0; PCout(9) = 0;		break;
			case 5:	PCout(6) = 0; PCout(7) = 1; PCout(8) = 0; PCout(9) = 1;		break;
			case 6:	PCout(6) = 0; PCout(7) = 0; PCout(8) = 0; PCout(9) = 1;		break;
			case 7:	PCout(6) = 1; PCout(7) = 0; PCout(8) = 0; PCout(9) = 1;		break;
		}
	}
	else
	{
		switch(x)
		{
			case 0:	PCout(6) = 1; PCout(7) = 0; PCout(8) = 0; PCout(9) = 1;		break;
			case 1:	PCout(6) = 0; PCout(7) = 0; PCout(8) = 0; PCout(9) = 1;		break;
			case 2:	PCout(6) = 0; PCout(7) = 1; PCout(8) = 0; PCout(9) = 1;		break;
			case 3:	PCout(6) = 0; PCout(7) = 1; PCout(8) = 0; PCout(9) = 0;		break;
			case 4:	PCout(6) = 0; PCout(7) = 1; PCout(8) = 1; PCout(9) = 0;		break;
			case 5:	PCout(6) = 0; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;		break;
			case 6:	PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;		break;
			case 7:	PCout(6) = 1; PCout(7) = 0; PCout(8) = 0; PCout(9) = 0;		break;
		}
	}
	
	
	delay_ms(speed);
}

