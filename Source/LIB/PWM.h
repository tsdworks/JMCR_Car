#ifndef __PWM_H__
#define __PWM_H__
/*
---- PWM Control Module ----
Author: Zhang Muhua
Date: 2019.2.7
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#define PWM_CYCLE 8000L
#define PWM_DUTY_MAX 100
#define PWM_DUTY_MIN 0

sbit PWM2 = P3^7;
sbit PWM3 = P2^1;

extern int lastDutyPWM2;
extern int lastDutyPWM3;

void PWM_Init();
void PWM2_Output(unsigned int duty);
void PWM3_Output(unsigned int duty);
void PWM_Dispose();

#endif
