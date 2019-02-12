#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "SENSOR.h"

u8 sensorData[SENSOR_NUM] = {0};
u8 sensorSample = 0;
u8 isSensorInit = 0;

//Init the Sensor
void Sensor_Init()
{
	if(isSensorInit)return;
	pinModeGroup(0, IO_MODE);
	Sensor_GetSample(); 
	isSensorInit = 1;
}

//Get Sensor Sample
void Sensor_GetSample()
{
	u8 i, sample;
	sample = 0;
	for(i = 0; i < 20; i++)
	{
		sample += digitalRead(IO_MODE, 0, L3);
		sample += digitalRead(IO_MODE, 0, R3);
	}
	sensorSample = sample / 40;
}

//Refresh Sensor Data
void Sensor_RefreshData()
{
	int i;
	for(i = 0; i < SENSOR_NUM; i++)
	{
		sensorData[i] = digitalRead(IO_MODE, 0, 0) == sensorSample;
	}
}

//Get Single Sensor Data
u8 Sensor_GetSingleData(u8 sensorID)
{
	Sensor_RefreshData();
	return digitalRead(IO_MODE, 0, sensorID) == sensorSample;
}

//Get Sensor Data for PID
int Sensor_GetData()
{
	u8 i;
	int leftValue, rightValue;
	leftValue = 0;
	rightValue = 0;
	Sensor_RefreshData();
	for(i = L0; i >= L3 ; i--)leftValue += sensorData[i] * (i - 4) * 20 + 10;
	for(i = R0; i <= R3; i++)rightValue += sensorData[i] * (3 - i) * 20 + 10;
	return leftValue - rightValue;
}


