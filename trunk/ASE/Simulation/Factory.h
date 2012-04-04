///////////////////////////////////////////////////////////
//  Factory.h
//  Implementation of the Class Factory
//  Created on:      04-kwi-2012 12:40:28
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_4170E875_EBC1_4fb4_8B79_FF9085BE2E54__INCLUDED_)
#define EA_4170E875_EBC1_4fb4_8B79_FF9085BE2E54__INCLUDED_

#include"Product.h"

class Factory
{

public:
	Factory();
	virtual ~Factory();
	int getIdleTime();
	Product manufactureProduct();

private:
	double constructionCost;
	double costPerCycle;
	double efficiency;
	int idleTime;

};
#endif // !defined(EA_4170E875_EBC1_4fb4_8B79_FF9085BE2E54__INCLUDED_)
