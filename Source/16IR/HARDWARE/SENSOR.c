#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "SENSOR.h"

u8 sensorData[SENSOR_NUM] = {0};
u8 sensorMap[SENSOR_MAP] = {7, 6, 5, 4, 3, 2, 1, 0};
int leftValue = 0;
int rightValue = 0;
u8 isSensorInit = 0;

//Init the Sensor
void Sensor_Init()
{
	if(isSensorInit)return;
	pinModeGroup(0, IO_MODE);
	pinMode(LD_GROUP, LD_ID, OUTPUT_PP);
	pinMode(CH_GROUP, CH_ID, OUTPUT_PP);
	//Init LED
	digitalWrite(OUTPUT_PP, LD_GROUP, LD_ID, 1);
	//Init Channel
	digitalWrite(OUTPUT_PP, CH_GROUP, CH_ID, 1);
	isSensorInit = 1;
}

//Refresh Sensor Data
void Sensor_RefreshData()
{
	int i;
	u8 roundNum;
	roundNum = SENSOR_NUM / 2;
	//Get Data 1 - 8
	digitalWrite(OUTPUT_PP, CH_GROUP, CH_ID, 1);
	delay_ms(WAIT_TIME);
	for(i = 0; i < roundNum; i++)
	{
		sensorData[i] = digitalRead(IO_MODE, 0, i) == SENSOR_SAMPLE;
	}
	//Get Data 9-16
	digitalWrite(OUTPUT_PP, CH_GROUP, CH_ID, 0);
	delay_ms(WAIT_TIME);
	for(i = roundNum; i < SENSOR_NUM; i++)
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
	for(i = L0; i >= L7 ; i--)leftValue = maxInt(leftValue, sensorData[i] * sensorMap[L0 - i]);
	for(i = R0; i <= R7; i++)rightValue = maxInt(rightValue, sensorData[i] * sensorMap[i - R0]);
	return rightValue - leftValue;
}
