#include "STC15.h"
#include "IO.h"
#include "PWM.h"
#include "STDFUNC.h"
#include "USART.h"
#include "PID.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"

#define true 1
#define CONTROL_INV 60

void JMCR_Car()
{
	PID_Calc(Sensor_GetData());
	Servo_SetAngle(PID_ServoAngle);
	Motor_Left(PID_LeftMotorPWM);
	Motor_Right(PID_RightMotorPWM);
}

void main()
{
	//Init Devices
	Servo_Attach();
	Motor_Init();
	Sensor_Init();
	//Serial1_Begin(115200L);
	//Init PID
	PID_Setup(0.3, 0, 0.1);
	//Wait for initializing
	delay_ms(CONTROL_INV);
	while(true)
	{
		JMCR_Car();
		//Serial1_SendByte(PID_ServoAngle);
		delay_ms(CONTROL_INV);
	}
}

