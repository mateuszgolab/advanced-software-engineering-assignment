///////////////////////////////////////////////////////////
//  Factory.cpp
//  Implementation of the Class Factory
//  Created on:      04-kwi-2012 12:40:28
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Factory.h"
#include "SimulationManager.h"


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

double Factory::manufacture()
{
	return 0.0;
}

FactoryState Factory::getState() const
{
	return FactoryState::IDLE;
}

void Factory::setProduct(Product product, int orderID)
{

}