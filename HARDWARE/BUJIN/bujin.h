#ifndef __BUJIN_H_
#define __BUJIN_H_
#include "sys.h"

void bujin_init();

void Moter_Go(u8 speed,u8 x);
void Moter_Go1(u8 speed,u8 flag,u8 x);
void Moter_Go2(u8 speed,u8 flag,u8 x);	
//void Moter_Go(u8 speed,u8 flag,u8 x);	

void Moter_Go_ahead(u8 speed,u8 x);
void Moter_Go_back(u8 speed,u8 x);
void Moter1_Stop();
void Moter2_Stop();
#endif