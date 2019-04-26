#pragma once
#include "Operate.h"
class Apply :
	public Operate
{
public:
	Apply(int applyIndex);
	virtual ~Apply();
	virtual void Do(Game* game);
};

