#pragma once
#include "Operate.h"
class Game;
class Calculate :
	public Operate
{
public:
	Calculate(int calType, int calNum1,int calNum2,int calRet);
	virtual ~Calculate();
	virtual void Do(Game* game);
};

