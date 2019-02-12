/*
---- Servo Control Module ----
Author: Zhang Muhua
Date: 2019.2.9 
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "SERVO.h"

u8 servoIOGroup;
u8 servoIONumber;
int servoAngle;
int highLevelCount;
int pulseWidthCount;

//10us@24.000Mhz
void Timer0Init(void)
{
	ET0 = 0;
	TR0 = 0;
	AUXR |= 0x80;
	TMOD &= 0xF0;
	TL0 = 0x10;
	TH0 = 0xFF;
	TF0 = 0;
	ET0 = 1;
}

//Timer0 ISP
void Timer0_ISP() interrupt 1
{
	TR0 = 0;
	if(pulseWidthCount < highLevelCount)
		digitalWrite(OUTPUT_PP, servoIOGroup, servoIONumber, 1);
	else 
		digitalWrite(OUTPUT_PP, servoIOGroup, servoIONumber, 0);
	pulseWidthCount = (pulseWidthCount + 1) % SERVO_PULSE_WIDTH;
	TR0 = 1;
}

//Attach Servo
void ServoAttach(u8 IOGroup, u8 IONumber)
{
	//Setup Servo
	servoIOGroup = IOGroup;
	servoIONumber = IONumber;
	servoAngle = 0;
	pulseWidthCount = 0;
	highLevelCount = SERVO_MID_PULSE;
	//Setup IO Mode
	pinMode(IOGroup, IONumber, OUTPUT_PP);
	digitalWrite(OUTPUT_PP, IOGroup, IONumber, 0);
	ServoSetAngle(SERVO_MID_ANGLE);
	//Setup Timer0
	Timer0Init();
}

//Set Servo Angle
void ServoSetAngle(u8 Angle)
{
	if(Angle < SERVO_MIN_ANGLE || Angle > SERVO_MAX_ANGLE || Angle == servoAngle)return;
	TR0 = 0;
	servoAngle = Angle;
	highLevelCount = (servoAngle * 10) / 18 + 100;
	TR0 = 1;
}
