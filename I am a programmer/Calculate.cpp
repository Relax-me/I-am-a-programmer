#include "stdafx.h"
#include "Calculate.h"

//CALCULATE_ADD�� CALCULATE_SUBTRACT�� CALCULATE_MULTIPLY�� CALCULATE_DIVIDE�� CALCULATE_COPY����
Calculate::Calculate(int calType, int calNum1, int calNum2, int calRet)
{
	this->calType = calType;
	this->calNum1 = calNum1;
	this->calNum2 = calNum2;
	this->calRet = calRet;
}


Calculate::~Calculate()
{
}