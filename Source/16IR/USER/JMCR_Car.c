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
#define CONTROL_INV 10
#define WAIT_INV 1000

void JMCR_Car()
{
	PID_Calc(Sensor_GetData());
	Servo_SetAngle(PID_ServoAngle);
	Motor_Left(PID_LeftMotorPWM);
	Motor_Right(PID_RightMotorPWM);
}

void main()
{
	u8 i;
	//Init Devices
	Motor_Init();
	Sensor_Init();
	Servo_Attach();
	//Init PID
	PID_Setup(0.45, 0.15, 0);
	//Serial1_Begin(115200);
	//Wait for initializing
	delay_ms(WAIT_INV);
	while (true)
	{
		JMCR_Car();
		//for(i = 0; i < 16; i++)Serial1_SendByte(sensorData[i]);
		//Serial1_SendByte(3);
		delay_ms(CONTROL_INV);
	}
}
