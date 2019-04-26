#pragma once
#define CALCULATE 01
#define CONTROL 02
#define APPLY 03
#define IN 04
#define OUT 05
#define CALCULATE_ADD 11
#define CALCULATE_SUBTRACT 12
#define CALCULATE_MULTIPLY 13
#define CALCULATE_DIVIDE 14
#define CALCULATE_COPY 15
#define CONTROL_BIGGER 21
#define CONTROL_LESSER 22
#define CONTROL_EQUALS 23
class Game;
class Operate
{
public:
	virtual ~Operate(){}
	virtual void Do(Game* game) = 0;
	int type;
	//////////////////////////
	int calType;
	int calNum1;
	int calNum2;
	int calRet;
	/////////////////////////////
	int conType;
	int conNum1;
	int conNum2;
	int conToIndex;
	/////////////////////////////
	int applyIndex;
	/////////////////////////////
	int inIndex;
	/////////////////////////////
	int outIndex;
};