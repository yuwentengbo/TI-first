#include "tar.h"
#include "led.h"
#include "delay.h"
#include "bujin.h"

//��һ��
void tar1()
{
	u8 i,j=0;
	LED0 = 0;
	LED1 = 0;
	
	/*while(1)
	{
		Moter_Go(6,0,i++);
		if(i == 8)	i=0;
	}*/
	while(1)
	{
		i=0;
		for(i=0;i<50;i++)
		{
			if(j == 8)	j=0;
			Moter_Go(6,0,j);
			j++;
		}
		
		j=0;
		for(i=0;i<50;i++)
		{
			if(j == 8)	j=0;
			Moter_Go(6,1,j);
			j++;
		}
	}
}

//�ڶ���
void tar2()
{
	while(1)
	{
		LED1 = 0;
		delay_ms(500);
		LED1 = 1;
		delay_ms(500);
	}
}


//������
void tar3()
{
	while(1)
	{
		LED0 = 0;
		delay_ms(500);
		LED0 = 1;
		delay_ms(500);
	}
}

