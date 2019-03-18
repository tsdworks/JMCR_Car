#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "SENSOR.h"

u8 sensorData[SENSOR_NUM] = {0};
u8 sensorMap[SENSOR_MAP] = {4, 3, 2, 1};
int leftValue = 0;
int rightValue = 0;
u8 isSensorInit = 0;

//Init the Sensor
void Sensor_Init()
{
	if(isSensorInit)return;
	pinModeGroup(0, IO_MODE);
	isSensorInit = 1;
}

//Refresh Sensor Data
void Sensor_RefreshData()
{
	int i;
	//Get Data 1-8
	for(i = 0; i < SENSOR_NUM; i++)
	{
		sensorData[i] = digitalRead(IO_MODE, 0, i) == SENSOR_SAMPLE;
	}
}

//Get Single Sensor Data
u8 Sensor_GetSingleData(u8 sensorID)
{
	Sensor_RefreshData();
	return digitalRead(IO_MODE, 0, sensorID) == SENSOR_SAMPLE;
}

//Get Sensor Data for PID
int Sensor_GetData()
{
	u8 i;
	leftValue = 0;
	rightValue = 0;
	Sensor_RefreshData();
	for(i = L0; i >= L3 ; i--)leftValue = maxInt(leftValue, sensorData[i] * sensorMap[L0 - i]);
	for(i = R0; i <= R3; i++)rightValue = maxInt(rightValue, sensorData[i] * sensorMap[i - R0]);
	return rightValue - leftValue;
}
