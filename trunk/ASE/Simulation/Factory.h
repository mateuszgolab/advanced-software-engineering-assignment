///////////////////////////////////////////////////////////
//  Factory.h
//  Implementation of the Class Factory
//  Created on:      04-kwi-2012 12:40:28
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_4170E875_EBC1_4fb4_8B79_FF9085BE2E54__INCLUDED_)
#define EA_4170E875_EBC1_4fb4_8B79_FF9085BE2E54__INCLUDED_

#include"Product.h"
#include"FactoryState.h"

class Factory
{

public:
	Factory();
	Factory(double efficiency);
	virtual ~Factory();
	int getIdleTime() const;
	FactoryState getState() const;
	double manufacture(Product* product);
	double manufacture();
	void setState(FactoryState state);
	void incIdleTime();

	static void setConstructionCost(double cost);
	static void setRunningCost(double cost);
	static double getConstructionCost();
	static double getRunningCost();
	static double getFactoryStartUpCost();

private:
	double efficiency;
	int idleTime;
	FactoryState state;
	Product* currentProduct;
	static double constructionCost;
	static double costPerCycle;
	static double startUpCost;

};
#endif // !defined(EA_4170E875_EBC1_4fb4_8B79_FF9085BE2E54__INCLUDED_)
