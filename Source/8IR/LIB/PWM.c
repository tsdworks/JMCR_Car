/*
---- PWM Control Module ----
Author: Zhang Muhua
Date: 2019.2.7
----------------------------
*/
#include "STC15.h"
#include "PWM.h"
#include "IO.h"

int lastDutyPWM2 = -1;
int lastDutyPWM3 = -1;

//Enable PWM2 et PWM3
void PWM_Init()
{
	//IO P-P Registers Setup
	pinMode(3, 7, OUTPUT);
	pinMode(2, 1, OUTPUT);
	//PWM Registers Setup
	P_SW2 |= 0x80;
	PWMCFG = 0x00;
	PWMCKS = 0x0f;
	PWMC = PWM_CYCLE;
	PWM2CR = 0x00;
	PWM3CR = 0x00;
	PWM2T1 = 0x0000;
	PWM2T2 = 0x0001;
	PWM3T1 = 0x0000;
	PWM3T2 = 0x0001;
	PWMCR |= 0x80;
	P_SW2 &= ~0x80;
	//Reset lastDuty Value
	lastDutyPWM2 = -1;
	lastDutyPWM3 = -1;
}

//PWM2 Duty Control
void PWM2_Output(unsigned int duty)
{
	if(duty == lastDutyPWM2)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x01;
		PWM2 = duty == PWM_DUTY_MAX;
	}
	else
	{
		P_SW2 |= 0x80;
		PWM2T1 = 0x00;
		PWM2T2 = duty * PWM_CYCLE / 100;
		P_SW2 &= ~0x80;
		PWMCR |= 0x01;
	}
	lastDutyPWM2 = duty;
}

//PWM3 Duty Control
void PWM3_Output(unsigned int duty)
{
	if(duty == lastDutyPWM3)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x02;
		PWM3 = duty == PWM_DUTY_MAX;
	}
	else
	{
		P_SW2 |= 0x80;
		PWM3T1 = 0x00;
		PWM3T2 = duty * PWM_CYCLE / 100;
		P_SW2 &= ~0x80;
		PWMCR |= 0x02;
	}
	lastDutyPWM3 = duty;
}

//Dispose PWM Function
void PWM_Dispose()
{
	P_SW2 |= 0x80;
	PWMCR = 0x00;
	P_SW2 &= ~0x80;
	PWM2 = PWM3 = 0;
}
