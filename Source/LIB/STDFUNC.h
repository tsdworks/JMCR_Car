#ifndef __STDFUNC_H__
#define __STDFUNC_H__
/*
---- STD Functions Module ----
Author: Zhang Muhua
Date: 2019.2.7
----------------------------
*/
#include "STC15.h"
#include "IO.h"
#include "PWM.h"

void delay_ms(unsigned int t);
int maxInt(int numA, int numB);
double maxDouble(double numA, double numB);
int minInt(int numA, int numB);
double minDouble(double numA, double numB);
int absInt(int num);
double absDouble(double num);

#endif
