#ifndef __PID_H__
#define __PID_H__
/*
---- PID Control Module ----
Author: Zhang Muhua
Date: 2019.2.11 
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"

#define MAX_ANGLE 145
#define MIN_ANGLE 35
#define MAX_INT 2000000000
#define MIN_INT -2000000000

//PID Paras
extern float PID_KP;
extern float PID_KI;
extern float PID_KD;
extern int pid_e;
extern long pid_i;
extern int pid_d;
extern int pid_le;

//Data for Apply
extern u8 PID_ServoAngle;
extern int PID_LeftMotorPWM;
extern int PID_RightMotorPWM;

void PID_Setup(float kp, float ki, float kd);
void PID_Calc(int sensorData);

#endif

