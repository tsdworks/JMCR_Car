#ifndef __SERVO_H__
#define __SERVO_H__
/*
---- Servo Control Module ----
Author: Zhang Muhua
Date: 2019.2.9 
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"

#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_ANGLE 0
#define SERVO_MID_ANGLE 90
#define SERVO_IO_GROUP 4
#define SERVO_IO_NUMBER 5

sbit servoPin = P4 ^ 5;

extern int servoAngle;
extern int servoHighFreq;

void Timer0Init();
void Timer3Init();
void Servo_Attach();
void Servo_SetAngle(u8 Angle);

#endif
