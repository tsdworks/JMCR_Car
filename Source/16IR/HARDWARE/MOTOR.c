/*
---- Motor Control Module ----
Author: Zhang Muhua
Date: 2019.2.11
Notice: PWM2 - Left - Motor A, PWM3 - Right - Motor B
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "PWM.h"
#include "MOTOR.h"

//Motor Init
void Motor_Init()
{
	int i;
	PWM_Init();
	for(i = AIN1; i <= BIN2 ; i++)
		pinMode(3, i, OUTPUT_PP);	
}

//Set Motor Left
void Motor_Left(int value)
{
	if(value > 0)
	{
		digitalWrite(OUTPUT_PP, 3, AIN1, 0);
		digitalWrite(OUTPUT_PP, 3, AIN2, 1);
	}
	else
	{
		digitalWrite(OUTPUT_PP, 3, AIN1, 1);
		digitalWrite(OUTPUT_PP, 3, AIN2, 0);
		value *= -1;
	}
	PWM2_Output(value > MOTOR_MAX_PWM ? MOTOR_MAX_PWM : value);
}

//Set Motor Right
void Motor_Right(int value)
{
	if(value > 0)
	{
		digitalWrite(OUTPUT_PP, 3, BIN1, 0);
		digitalWrite(OUTPUT_PP, 3, BIN2, 1);
	}
	else
	{
		digitalWrite(OUTPUT_PP, 3, BIN1, 1);
		digitalWrite(OUTPUT_PP, 3, BIN2, 0);
		value *= -1;
	}
	PWM3_Output(value > MOTOR_MAX_PWM ? MOTOR_MAX_PWM : value);
}
