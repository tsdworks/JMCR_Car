#ifndef __IO_H__
#define __IO_H__
/*
---- IO Control Module ----
Author: Zhang Muhua
Date: 2019.2.7
----------------------------
*/
#include "STC15.h"

#define INPUT_PULLUP 0
#define INPUT 1
#define OUTPUT 2
#define OUTPUT_PP 3

void pinMode(u8 IOGroup, u8 IONumber, u8 IOType);
void pinModeGroup(u8 IOGroup, u8 IOType);
u8 digitalRead(u8 IOMode, u8 IOGroup, u8 IONumber);
u8 digitalReadGroup(u8 IOMode, u8 IOGroup);
void digitalWrite(u8 IOMode, u8 IOGroup, u8 IONumber, u8 content);
void digitalWriteGroup(u8 IOMode, u8 IOGroup, u8 content);

#endif
