///////////////////////////////////////////////////////////
//  Factory.cpp
//  Implementation of the Class Factory
//  Created on:      04-kwi-2012 12:40:28
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Factory.h"
#include "SimulationManager.h"


double Factory::constructionCost = DEFAULT_FACTORY_CONSTRUCTION_COST;
double Factory::costPerCycle = DEFAULT_FACTORY_RUNNING_COST;

Factory::Factory() : efficiency(SimulationManager::randomNumberGenerator(0.0, 2.0))
{

}

Factory::Factory(double efficiency) : efficiency(efficiency)
{

}

Factory::~Factory(){

}

int Factory::getIdleTime() const
{

	return 0;
}

void Factory::manufacture(Product & product)
{
	 product.produce(efficiency);
}

FactoryState Factory::getState() const
{
	return FactoryState::IDLE;
}


void Factory::setConstructionCost(double cost)
{
	costPerCycle = cost;
}

void Factory::setRunningCost(double cost)
{
	constructionCost = cost;
}

double Factory::getConstructionCost()
{
	return constructionCost;
}

double Factory::getRunningCost()
{
	return costPerCycle;
}