#ifndef __SENSOR_H__
#define __SENSOR_H__
/*
---- Sensor Support Module ----
Author: Zhang Muhua
Date: 2019.2.11
Device: FST SEN2020
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"

#define IO_MODE INPUT
#define SENSOR_NUM 16 
#define SENSOR_MAP 8
#define LD_GROUP 1
#define LD_ID 0
#define CH_GROUP 1
#define CH_ID 1
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define L0 15
#define L1 14
#define L2 13
#define L3 12
#define L4 11
#define L5 10
#define L6 9
#define L7 8

#define WAIT_TIME 2

//0 - Black Line, 1 - White Line
#define SENSOR_SAMPLE 0

extern u8 sensorData[SENSOR_NUM];
extern u8 sensorMap[SENSOR_MAP];
extern u8 isSensorInit;
extern int leftValue;
extern int rightValue;

void Sensor_Init();
void Sensor_RefreshData();
u8 Sensor_GetSingleData(u8 sensorID);
int Sensor_GetData();

#endif
