#ifndef __MOTOR_H__
#define __MOTOR_H__
/*
---- Motor Control Module ----
Author: Zhang Muhua
Date: 2019.2.11
Notice: PWM2 - Right - Motor A, PWM3 - Left - Motor B
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "PWM.h"

#define AIN1 3
#define AIN2 4
#define BIN1 5
#define BIN2 6

#define MOTOR_MAX_PWM 80

void Motor_Init();
void Motor_Left(int value);
void Motor_Right(int value);

#endif
