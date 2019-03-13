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

#define IO_MODE INPUT_PULLUP
#define SENSOR_NUM 8
#define SENSOR_MAP 4
#define L0 7
#define L1 6
#define L2 5
#define L3 4
#define R3 3
#define R2 2
#define R1 1
#define R0 0

extern u8 sensorData[SENSOR_NUM];
extern u8 sensorMap[SENSOR_MAP];
extern u8 sensorSample;
extern u8 isSensorInit;

void Sensor_Init();
void Sensor_GetSample();
void Sensor_RefreshData();
u8 Sensor_GetSingleData(u8 sensorID);
int Sensor_GetData();

#endif
