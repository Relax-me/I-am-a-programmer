#pragma once
#include "Operate.h"
class In :
	public Operate
{
public:
	In(int inIndex);
	virtual ~In();
	virtual void Do(Game* game);
};

