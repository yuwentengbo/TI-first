#include "timer.h"
#include "led.h"

/*
	定时器3初始化
	arr 自动重装载值
	psc 分频因子
*/
void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 	

	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM3, //TIM3
		TIM_IT_Update ,
		ENABLE  //使能
	);
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  
	TIM_Cmd(TIM3,DISABLE);

}

//得到计数值
u32 Tim3_Get_HignCounter(void)
{
	return TIM3->CNT;
}

//打开定时器
void TIM3_Start()
{
	TIM3->CNT = 0;
	TIM_Cmd(TIM3,ENABLE);
}


//关闭定时器
void TIM3_Close()
{
	TIM_Cmd(TIM3,DISABLE);
}

//TIM3服务函数
void TIM3_IRQHandler(void)   
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) 
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  
		LED1=!LED1;
	}
}
