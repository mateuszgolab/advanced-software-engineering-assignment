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
double Factory::startUpCost = DEFAULT_IDLE_FACTORY_STARTUP_COST;

Factory::Factory() : efficiency(SimulationManager::randomNumberGenerator(1.0, 4.0)), currentProduct(NULL), state(READY), idleTime(0)
{

}

Factory::Factory(double efficiency) : efficiency(efficiency), currentProduct(NULL), state(READY), idleTime(0)
{

}

Factory::~Factory(){

}

int Factory::getIdleTime() const
{
	return idleTime;
}

double Factory::manufacture(Product* product)
{
	currentProduct = product;
	return product->produce(efficiency);
}

double Factory::manufacture()
{
	return currentProduct->produce(efficiency);
}

FactoryState Factory::getState() const
{
	return state;
}

void Factory::setConstructionCost(double cost)
{
	constructionCost = cost;
}

void Factory::setRunningCost(double cost)
{
	costPerCycle = cost;
}

double Factory::getConstructionCost()
{
	return constructionCost;
}

double Factory::getRunningCost()
{
	return costPerCycle;
}

double Factory::getFactoryStartUpCost()
{
	return startUpCost;
}

void Factory::setState(FactoryState state)
{
	this->state = state;
	idleTime = 0;
}

void Factory::incIdleTime()
{
	idleTime++;
}