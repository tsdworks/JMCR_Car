/*
---- USART Module ----
Author: Zhang Muhua
Date: 2019.2.9 
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "USART.h"

u8 readBuffer[READ_BUFFER_LENGTH];
u8 readBufferLength;
u8 readBufferHead;
u8 readBufferTail;

//Begin the Serial1
void Serial1_Begin(unsigned long BAUD)
{
	//Setup IO Mode
	pinMode(3, 0, INPUT_PULLUP);
	pinMode(3, 1, OUTPUT);
	//Setup USART Registers
	ACC = P_SW1;
  ACC &= ~(S1_S0 | S1_S1);
  P_SW1 = ACC;
  AUXR |= 0x40;
  TMOD = 0x00;
  TL1 = (65536 - (FOSC / 4 / BAUD));
  TH1 = (65536 - (FOSC / 4 / BAUD)) >> 8;
  TR1 = 1;
  ES = 1;
  EA = 1;
	//Clear Buffer
	readBufferLength = 0;
	readBufferHead = 0;
	readBufferTail = 0;
}

//Send One Char via Serial1
void Serial1_SendByte(u8 s)
{
	SBUF = s;
	while(!TI);
	TI = 0;
}

//Send One String via Serial1
void Serial1_SendStr(u8 *s)
{
	while(*s)
	{
		Serial1_SendByte(*s++);
	}
}

//Send Fixed Length String via Serial1
void Serial1_SendLenStr(u8 *s, int length)
{
	while(length && *s)
	{
		Serial1_SendByte(*s++);
		length--;
	}
}

//Serial ISP
void Serial1_ISP() interrupt 4
{
	if(RI)
	{
		RI = 0;
		if(readBufferLength > READ_BUFFER_LENGTH)
		{
			readBufferHead = (readBufferHead + 1) % READ_BUFFER_LENGTH;
			readBufferLength = 	READ_BUFFER_LENGTH;
		}
		readBufferLength++;
		readBuffer[readBufferTail] = SBUF;
		readBufferTail = (readBufferTail + 1) % READ_BUFFER_LENGTH;
	}
	if(TI)
	{
		TI = 0;
	}
}

//Is Serial1 Has Data To Read 
u8 Serial1_Available()
{
	return readBufferLength > 0;
}

//Read Data in Serial1 Buffer Area
u8 Serial1_ReadByte()
{
	u8 retValue = 0;
	if(Serial1_Available())
	{
		retValue = readBuffer[readBufferHead];
		readBufferHead = (readBufferHead + 1) % READ_BUFFER_LENGTH;
		readBufferLength--;
	}
	return retValue;
}
