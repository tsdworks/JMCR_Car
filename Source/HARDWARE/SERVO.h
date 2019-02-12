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
#define SERVO_MAX_PULSE 200
#define SERVO_MIN_PULSE 100
#define SERVO_MID_PULSE 150
#define SERVO_PULSE_WIDTH 2000
#define TIMER_DIV 10

extern u8 servoIOGroup;
extern u8 servoIONumber;
extern int servoAngle;
extern int highLevelCount;
extern int pulseWidthCount;

void Timer0Init();
void ServoAttach(u8 IOGroup, u8 IONumber);
void ServoSetAngle(u8 Angle);

#endif
