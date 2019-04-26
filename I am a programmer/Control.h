#pragma once
#include "Operate.h"
class Control :
	public Operate
{
public:
	Control(int conType, int conNum1, int conNum2, int conToIndex);
	virtual ~Control();
	virtual void Do(Game* game);
};

