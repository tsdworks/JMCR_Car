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

int servoAngle;
int servoHighFreq;

//1.5ms@24.000Mhz
void Timer0Init(void)
{
	ET0 = 0;
	TR0 = 0;
	AUXR |= 0x80;
	TMOD &= 0xF0;	
	TL0 = 0x60;
	TH0 = 0x73;
	TF0 = 0;
	ET0 = 1;
	EA = 1;
}

//20ms @24.000Mhz
void Timer2Init(void)
{
	AUXR &= 0xFB;
	T2L = 0xc0;
	T2H = 0x63;
	IE2 |= 0x04;
	EA = 1;
}

//Timer0 ISP
void Timer0_ISP() interrupt 1
{
	servoPin = 0;
	TR0 = 0;
}

//Timer2 ISP
void Timer2_ISP() interrupt 12
{
	servoPin = 1;
	TR0	= 1;
}

//Attach Servo 
void Servo_Attach()
{		
	//Setup Servo
	servoAngle = 0;
	//Setup IO Mode
	pinMode(SERVO_IO_GROUP, SERVO_IO_NUMBER, OUTPUT_PP);
	digitalWrite(OUTPUT_PP, SERVO_IO_GROUP, SERVO_IO_NUMBER, 0);
	//Setup Timer0 et Timer2
	Timer0Init();
	Timer2Init();
	//Reset Servo Angle
	Servo_SetAngle(SERVO_MID_ANGLE);
}

//Set Servo Angle
void Servo_SetAngle(u8 Angle)
{
	if(Angle < SERVO_MIN_ANGLE || Angle > SERVO_MAX_ANGLE || Angle == servoAngle)return;
	//Timer Stop
	TR0 = 0;
	AUXR &= ~0x10;
	//Set Servo Timer
	servoPin = 0;
	servoAngle = Angle;
	servoHighFreq = 100000L / ((servoAngle * 10) / 9 + 50);
	TL0 = (65536 - (long)(FOSC / 1 / servoHighFreq)) % 256;
	TH0 = (65536 - (long)(FOSC / 1 / servoHighFreq)) / 256;
	servoPin = 1;
	//Timer Start
	TR0 = 1;
	AUXR |= 0x10;
}
