/*
---- IO Control Module ----
Author: Zhang Muhua
Date: 2019.2.7
----------------------------
*/
#include "STC15.h"
#include "IO.h"

//Setup IO Mode
void pinMode(u8 IOGroup, u8 IONumber, u8 IOType)
{
	u8 regVal;
	regVal = 1<<IONumber;
	if(IOType == INPUT_PULLUP || IOType == OUTPUT)
	{
		switch (IOGroup)
		{
			case 0:
			{
				P0M1 &= ~regVal;
				P0M0 &= ~regVal;
				P0 &= ~regVal;
			}
			break;
			case 1:
			{
				P1M1 &= ~regVal;
				P1M0 &= ~regVal;
				P1 &= ~regVal;
			}
			break;
			case 2:
			{
				P2M1 &= ~regVal;
				P2M0 &= ~regVal;
				P2 &= ~regVal;
			}
			break;
			case 3:
			{
				P3M1 &= ~regVal;
				P3M0 &= ~regVal;
				P3 &= ~regVal;
			}
			break;
			case 4:
			{
				P4M1 &= ~regVal;
				P4M0 &= ~regVal;
				P4 &= ~regVal;
			}
			break;
		}
	}
	else if(IOType == INPUT)
	{
		switch (IOGroup)
		{
			case 0:
			{
				P0M1 |= regVal;
				P0M0 &= ~regVal;
				P0 &= ~regVal;
			}
			break;
			case 1:
			{
				P1M1 |= regVal;
				P1M0 &= ~regVal;
				P1 &= ~regVal;
			}
			break;
			case 2:
			{
				P2M1 |= regVal;
				P2M0 &= ~regVal;
				P2 &= ~regVal;
			}
			break;
			case 3:
			{
				P3M1 |= regVal;
				P3M0 &= ~regVal;
				P3 &= ~regVal;
			}
			break;
			case 4:
			{
				P4M1 |= regVal;
				P4M0 &= ~regVal;
				P4 &= ~regVal;
			}
			break;
		}
	}
	else if(IOType == OUTPUT_PP)
	{
		switch (IOGroup)
		{
			case 0:
			{
				P0M1 &= ~regVal;
				P0M0 |= regVal;
				P0 &= ~regVal;
			}
			break;
			case 1:
			{
				P1M1 &= ~regVal;
				P1M0 |= regVal;
				P1 &= ~regVal;
			}
			break;
			case 2:
			{
				P2M1 &= ~regVal;
				P2M0 |= regVal;
				P2 &= ~regVal;
			}
			break;
			case 3:
			{
				P3M1 &= ~regVal;
				P3M0 |= regVal;
				P3 &= ~regVal;
			}
			break;
			case 4:
			{
				P4M1 &= ~regVal;
				P4M0 |= regVal;
				P4 &= ~regVal;
			}
			break;
		}
	}
}

//Setup Groups Of IO Pins Mode
void pinModeGroup(u8 IOGroup, u8 IOType)
{
	if(IOType == INPUT_PULLUP || IOType == OUTPUT)
	{
		switch (IOGroup)
		{
			case 0:
			{
				P0M1 = 0x00;
				P0M0 = 0x00;
				P0 = 0x00;
			}
			break;
			case 1:
			{
				P1M1 = 0x00;
				P1M0 = 0x00;
				P1 = 0x00;
			}
			break;
			case 2:
			{
				P2M1 = 0x00;
				P2M0 = 0x00;
				P2 = 0x00;
			}
			break;
			case 3:
			{
				P3M1 = 0x00;
				P3M0 = 0x00;
				P3 = 0x00;
			}
			break;
			case 4:
			{
				P4M1 = 0x00;
				P4M0 = 0x00;
				P4 = 0x00;
			}
			break;
		}
	}
	else if(IOType == INPUT)
	{
		switch (IOGroup)
		{
			case 0:
			{
				P0M1 = 0xff;
				P0M0 = 0x00;
				P0 = 0x00;
			}
			break;
			case 1:
			{
				P1M1 = 0xff;
				P1M0 = 0x00;
				P1 = 0x00;
			}
			break;
			case 2:
			{
				P2M1 = 0xff;
				P2M0 = 0x00;
				P2 = 0x00;
			}
			break;
			case 3:
			{
				P3M1 = 0xff;
				P3M0 = 0x00;
				P3 = 0x00;
			}
			break;
			case 4:
			{
				P4M1 = 0xff;
				P4M0 = 0x00;
				P4 = 0x00;
			}
			break;
		}
	}
	else if(IOType == OUTPUT_PP)
	{
		switch (IOGroup)
		{
			case 0:
			{
				P0M1 = 0x00;
				P0M0 = 0xff;
				P0 = 0x00;
			}
			break;
			case 1:
			{
				P1M1 = 0x00;
				P1M0 = 0xff;
				P1 = 0x00;
			}
			break;
			case 2:
			{
				P2M1 = 0x00;
				P2M0 = 0xff;
				P2 = 0x00;
			}
			break;
			case 3:
			{
				P3M1 = 0x00;
				P3M0 = 0xff;
				P3 = 0x00;
			}
			break;
			case 4:
			{
				P4M1 = 0x00;
				P4M0 = 0xff;
				P4 = 0x00;
			}
			break;
		}
	}
}

//Read A IO Pin
u8 digitalRead(u8 IOMode, u8 IOGroup, u8 IONumber)
{
	u8 regVal = 1<<IONumber;
	if(IOMode == INPUT_PULLUP)
	{
		switch(IOGroup)
		{
			case 0:
			{
				P0 |= regVal;
				return (P0>>IONumber) & 0x01;
			}
			break;
			case 1:
			{
				P1 |= regVal;
				return (P1>>IONumber) & 0x01;
			}
			break;
			case 2:
			{
				P2 |= regVal;
				return (P2>>IONumber) & 0x01;
			}
			break;
			case 3:
			{
				P3 |= regVal;
				return (P3>>IONumber) & 0x01;
			}
			break;
			case 4:
			{
				P4 |= regVal;
				return (P4>>IONumber) & 0x01;
			}
			break;
		}
	}
	else if(IOMode == INPUT)
	{
		switch(IOGroup)
		{
			case 0:
				return (P0>>IONumber) & 0x01;
				break;
			case 1:
				return (P1>>IONumber) & 0x01;
				break;
			case 2:
				return (P2>>IONumber) & 0x01;
				break;
			case 3:
				return (P3>>IONumber) & 0x01;
				break;
			case 4:
				return (P4>>IONumber) & 0x01;
				break;
		}
	}
	return 0x00;
}

//Read A Group Of IO Pins
u8 digitalReadGroup(u8 IOMode, u8 IOGroup)
{
	if(IOMode == INPUT_PULLUP)
	{
		switch(IOGroup)
		{
			case 0:
			{
				P0 = 0xff;
				return P0;
			}
			break;
			case 1:
			{
				P1 = 0xff;
				return P1;
			}
			break;
			case 2:
			{
				P2 = 0xff;
				return P2;
			}
			break;
			case 3:
			{
				P3 = 0xff;
				return P3;
			}
			break;
			case 4:
			{
				P4 = 0xff;
				return P4;
			}
			break;
		}
	}
	else if(IOMode == INPUT)
	{
		switch(IOGroup)
		{
			case 0:
				return P0;
				break;
			case 1:
				return P1;
				break;
			case 2:
				return P2;
				break;
			case 3:
				return P3;
				break;
			case 4:
				return P4;
				break;
		}
	}
	return 0x00;
}

//Write to A IO Pin
void digitalWrite(u8 IOMode, u8 IOGroup, u8 IONumber, u8 content)
{
	u8 regVal;
	if(IOMode != OUTPUT && IOMode != OUTPUT_PP)return;
	regVal = 1<<IONumber;
	if(content)
	{
		switch(IOGroup)
		{
			case 0:
				P0 |= regVal;
				break;
			case 1:
				P1 |= regVal;
				break;
			case 2:
				P2 |= regVal;
				break;
			case 3:
				P3 |= regVal;
				break;
			case 4:
				P4 |= regVal;
				break;
		}
	}
	else
	{
		switch(IOGroup)
		{
			case 0:
				P0 &= ~regVal;
				break;
			case 1:
				P1 &= ~regVal;
				break;
			case 2:
				P2 &= ~regVal;
				break;
			case 3:
				P3 &= ~regVal;
				break;
			case 4:
				P4 &= ~regVal;
				break;
		}
	}
}

//Write to A Groupp of IO Pins
void digitalWriteGroup(u8 IOMode, u8 IOGroup, u8 content)
{
	if(IOMode != OUTPUT && IOMode != OUTPUT_PP)return;
	if(content)
	{
		switch(IOGroup)
		{
			case 0:
				P0 = 0xff;
				break;
			case 1:
				P1 = 0xff;
				break;
			case 2:
				P2 = 0xff;
				break;
			case 3:
				P3 = 0xff;
				break;
			case 4:
				P4 = 0xff;
				break;
		}
	}
	else
	{
		switch(IOGroup)
		{
			case 0:
				P0 = 0x00;
				break;
			case 1:
				P1 = 0x00;
				break;
			case 2:
				P2 = 0x00;
				break;
			case 3:
				P3 = 0x00;
				break;
			case 4:
				P4 = 0x00;
				break;
		}
	}
}
