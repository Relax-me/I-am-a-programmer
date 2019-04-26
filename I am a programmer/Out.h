#pragma once
#include "Operate.h"
class Out :
	public Operate
{
public:
	Out(int outIndex);
	virtual ~Out();
	virtual void Do(Game* game);
};

