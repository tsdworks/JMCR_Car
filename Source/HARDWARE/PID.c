#include "STC15.h"
#include "IO.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"
#include "PID.h"

//PID Paras
float PID_KP;
float PID_KI;
float PID_KD;
int pid_e;
long pid_i;
int pid_d;
int pid_le;

//Data for Apply
u8 PIDservoAngle = 90;
int leftMotorPWM = 100;
int rightMotorPWM = 100;

void PID_Setup(float kp, float ki, float kd)
{
	PID_KP = kp;
	PID_KI = ki;
	PID_KD = kd;
	pid_e = 0;
	pid_i = 0;
	pid_d = 0;
	pid_le = 0;
}

void PID_Calc(int sensorData)
{
	leftMotorPWM = 100;
	rightMotorPWM = 100;
	pid_e = sensorData;
	pid_i += pid_e;
	pid_d = pid_e - pid_le;
	PIDservoAngle = 90 + (u8)(PID_KP * pid_e + PID_KI * pid_i + PID_KD * pid_d);
	if(servoAngle > 90)leftMotorPWM -= servoAngle - 90;
	else rightMotorPWM -= 90 - servoAngle; 
}

