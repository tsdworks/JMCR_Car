#ifndef __USART_H__
#define __USART_H__
/*
---- USART Module ----
Author: Zhang Muhua
Date: 2019.2.9 
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"

//Define Default BAUD rate
#define DEFAULT_BAUD 9600L 
//Define Read Buffer Length
#define READ_BUFFER_LENGTH 64
#define S1_S0 0x40
#define S1_S1 0x80  

extern u8 readBuffer[READ_BUFFER_LENGTH];
extern u8 readBufferLength;
extern u8 readBufferHead;
extern u8 readBufferTail;

void Serial1_Begin(unsigned long BAUD);
void Serial1_SendByte(u8 s);
void Serial1_SendStr(u8 *s);
void Serial1_SendLenStr(u8 *s, int length);
u8 Serial1_Available();
u8 Serial1_ReadByte();

#endif

