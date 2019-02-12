#include "STC15.h"
#include "IO.h"
#include "PWM.h"
#include "STDFUNC.h"
#include "USART.h"
#include "PID.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"

u8 callControl = 0;

//2ms@24.0000Mhz
void Timer2Init(void)
{
	AUXR |= 0x04;
	T2L = 0x80;
	T2H = 0x44;
	AUXR |= 0x10;
	EA = 1;
}

void Timer2_ISP() interrupt 12
{
	callControl = 1;
}

//Car Main Control
void JMCR_Car()
{
	PID_Calc(Sensor_GetData());
	ServoSetAngle(PIDservoAngle);
	Motor_Left(leftMotorPWM);
	Motor_Right(rightMotorPWM);
	callControl = 0;
}

void main()
{
	//Init Devices
	ServoAttach(4, 5);
	Motor_Init();
	Sensor_Init();
	PID_Setup(2, 0.01, 0.2);
	//Cold Start
	JMCR_Car();
	//Init Timer2
	Timer2Init();
	while(1)
	{
		if(callControl)JMCR_Car();
	}
}

