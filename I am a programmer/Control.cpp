#include "stdafx.h"
#include "Control.h"

//CONTROL_BIGGER���� CONTROL_LESSERС�� CONTROL_EQUALS����
Control::Control(int conType, int conNum1, int conNum2, int conToIndex)
{
	this->conType = conType;
	this->conNum1 = conNum1;
	this->conNum2 = conNum2;
	this->conToIndex = conToIndex;
}


Control::~Control()
{
}
