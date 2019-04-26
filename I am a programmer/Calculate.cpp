#include "stdafx.h"
#include "Calculate.h"

//CALCULATE_ADD¼Ó CALCULATE_SUBTRACT¼õ CALCULATE_MULTIPLY³Ë CALCULATE_DIVIDE³ý CALCULATE_COPY¿½±´
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