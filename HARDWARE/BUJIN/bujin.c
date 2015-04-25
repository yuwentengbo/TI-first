#include "bujin.h"
#include "delay.h"

/*
	���������ʼ��
	PC6,7,8,9
*/
void bujin_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
}

//1ֹͣ
void Moter1_Stop()
{
	PAout(4) = 0; PAout(5) = 0; PAout(6) = 0; PAout(7) = 0;
}


//2ֹͣ
void Moter2_Stop()
{
	PAout(1) = 0; PAout(2) = 0; PAout(3) = 0; PAout(4) = 0;
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
void Moter_Go1(u8 speed,u8 flag)		
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
}


void Moter_Go2(u8 speed,u8 flag)		
{
	if(flag == 0)
	{
		PAout(11) = 1; PAout(12) = 0; PAout(13) = 1; PAout(14) = 0;
		delay_ms(speed);
		
		PAout(11) = 0; PAout(12) = 1; PAout(13) = 1; PAout(14)= 0;
		delay_ms(speed);
		
		PAout(11) = 0; PAout(12) = 1; PAout(13) = 0; PAout(14) = 1;
		delay_ms(speed);
		
		PAout(11) = 1; PAout(12) = 0;  PAout(13)= 0;  PAout(14) = 1;
		delay_ms(speed);
	}
	else
	{
		PAout(11) = 1;  PAout(12) = 0;  PAout(13)= 0;  PAout(14) = 1;
		delay_ms(speed);
			
		PAout(11)= 0;  PAout(12) = 1;  PAout(13) = 0;  PAout(14)= 1;
		delay_ms(speed);

		PAout(11) = 0;  PAout(12) = 1; PAout(13) = 1;  PAout(14)= 0;
		delay_ms(speed);
		
		PAout(11)= 1;  PAout(12) = 0; PAout(13) = 1;   PAout(14) = 0;
		delay_ms(speed);
	}
}

	
*/
/*
PC67	һ��
PC89
������0.9��
speed  �ٶ� 
flag  ��ת��ת
x	   ϸ�ֵ�ÿһ��
*/	

void Moter_Go_ahead(u8 speed,u8 x)
{
	switch(x)
	{
			case 0:	PAout(0) = 1;  PAout(1) = 0;  PAout(2) = 0;  PAout(3) = 1;	
					PAout(4) = 1;  PAout(5) = 0;  PAout(6) = 0;  PAout(7) = 1;
					break;
			case 1:	PAout(0) = 0;  PAout(1)  = 0; PAout(2) = 0;  PAout(3) = 1;	
					PAout(4) = 0;  PAout(5) = 0;  PAout(6) = 0;  PAout(7) = 1;	
					break;
			case 2:	PAout(0) = 0; PAout(1) = 1;  PAout(2) = 0; PAout(3) = 1;		
					PAout(4)  = 0; PAout(5) = 1; PAout(6) = 0; PAout(7)= 1;
					break;
			case 3:	PAout(0) = 0; PAout(1)  = 1; PAout(2) = 0; PAout(3) = 0;	
					PAout(4)  = 0; PAout(5) = 1;  PAout(6) = 0; PAout(7) = 0;	
					break;
			case 4:	PAout(0) = 0; PAout(1)  = 1; PAout(2) = 1; PAout(3) = 0;	
					PAout(4)  = 0;  PAout(5) = 1;  PAout(6) = 1; PAout(7) = 0;
					break;
			case 5:	PAout(0) = 0; PAout(1)  = 0; PAout(2) = 1; PAout(3) = 0;	
					PAout(4) = 0;  PAout(5) = 0;  PAout(6) = 1; PAout(7) = 0;
					break;
			case 6:	PAout(0) = 1; PAout(1) = 0; PAout(2) = 1; PAout(3) = 0;	
					PAout(4)  = 1;  PAout(5) = 0;  PAout(6)= 1; PAout(7) = 0;	
					break;
			case 7:	PAout(0) = 1; PAout(1)  = 0; PAout(2) = 0; PAout(3) = 0;	
					PAout(4)  = 1; PAout(5) = 0;  PAout(6) = 0; PAout(7) = 0;
	}
	
	delay_ms(speed);
}

void Moter_Go_back(u8 speed,u8 x)
{
	switch(x)
	{
		case 0:	PAout(0) = 1; PAout(1) = 0; PAout(2) = 0; PAout(3) = 0;	
				PAout(4)  = 1; PAout(5) = 0;  PAout(6) = 0; PAout(7) = 0;
				break;
		case 1:	PAout(0) = 1; PAout(1) = 0; PAout(2) = 1; PAout(3) = 0;	
				PAout(4)  = 1;  PAout(5) = 0;  PAout(6)= 1; PAout(7) = 0;	
				break;
			
		case 2:	PAout(0) = 0; PAout(1) = 0; PAout(2) = 1; PAout(3) = 0;	
				PAout(4) = 0;  PAout(5) = 0;  PAout(6) = 1; PAout(7) = 0;
				break;
		
		case 3:	PAout(0) = 0; PAout(1) = 1; PAout(2) = 1; PAout(3) = 0;	
				PAout(4)  = 0;  PAout(5) = 1;  PAout(6) = 1; PAout(7) = 0;
				break;
		case 4:	PAout(0) = 0; PAout(1) = 1; PAout(2) = 0; PAout(3) = 0;	
				PAout(4)  = 0; PAout(5) = 1;  PAout(6) = 0; PAout(7) = 0;	
				break;
		case 5:	PAout(0) = 0; PAout(1) = 1; PAout(2) = 0; PAout(3) = 1;		
				PAout(4)  = 0; PAout(5) = 1; PAout(6) = 0; PAout(7)= 1;
				break;
		case 6:	PAout(0) = 0; PAout(1) = 0; PAout(2) = 0; PAout(3) = 1;	
				PAout(4)  = 0;  PAout(5) = 0;  PAout(6) = 0;PAout(7) = 1;	
				break;
		case 7:	PAout(0) = 1; PAout(1) = 0; PAout(2) = 0; PAout(3) = 1;	
				PAout(4)  = 1; PAout(5) = 0;  PAout(6) = 0; PAout(7) = 1;
				break;	
	}
	
	delay_ms(speed);
}

/*
void Moter_Go1(u8 speed,u8 flag,u8 x)		
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

void Moter_Go2(u8 speed,u8 flag,u8 x)		
{
	if(flag == 0)
	{
		switch(x)
		{
			case 0:	PAout(1)  = 1; PAout(2) = 0;  PAout(3) = 0; PAout(4) = 0;		break;
			case 1:PAout(1)  = 1; PAout(2) = 0;  PAout(3) = 1; PAout(4) = 0;		break;
			case 2:	PAout(1)  = 0; PAout(2) = 0;  PAout(3) = 1; PAout(4) = 0;		break;
			case 3:	PAout(1)  = 0;  PAout(2) = 1;  PAout(3) = 1; PAout(4) = 0;		break;
			case 4:	PAout(1)  = 0;  PAout(2) = 1;  PAout(3) = 0; PAout(4)= 0;		break;
			case 5:	PAout(1)  = 0; PAout(2) = 1;  PAout(3) = 0; PAout(4) = 1;		break;
			case 6:	PAout(1)  = 0;  PAout(2) = 0;  PAout(3) = 0; PAout(4) = 1;		break;
			case 7:PAout(1)  = 1;  PAout(2) = 0;  PAout(3) = 0;PAout(4) = 1;		break;
		}
	}
	else
	{
		switch(x)
		{
			case 0:PAout(1)  = 1; PAout(2) = 0;  PAout(3) = 0; PAout(4) = 1;		break;
			case 1:	PAout(1)  = 0;  PAout(2) = 0;  PAout(3) = 0;PAout(4) = 1;		break;
			case 2:PAout(1)  = 0; PAout(2) = 1; PAout(3) = 0; PAout(4)= 1;		break;
			case 3:	PAout(1)  = 0; PAout(2) = 1;  PAout(3) = 0; PAout(4) = 0;		break;
			case 4:PAout(1)  = 0;  PAout(2) = 1;  PAout(3) = 1; PAout(4) = 0;		break;
			case 5:	PAout(1) = 0;  PAout(2) = 0;  PAout(3) = 1; PAout(4) = 0;		break;
			case 6:PAout(1)  = 1;  PAout(2) = 0;  PAout(3)= 1; PAout(4) = 0;		break;
			case 7:	PAout(1)  = 1; PAout(2) = 0;  PAout(3) = 0; PAout(4) = 0;		break;
		}
	}
	
	
	delay_ms(speed);
}

*/
