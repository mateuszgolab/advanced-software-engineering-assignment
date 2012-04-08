///////////////////////////////////////////////////////////
//  Producer.cpp
//  Implementation of the Class Producer
//  Created on:      03-kwi-2012 23:54:54
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Producer.h"
#include "Model.h"
#include "SimulationManager.h"

using namespace std;

int Producer::idGenerator = 0;
int Producer::threshold = 50;

Producer::Producer(double cash) : cash(cash), numberOfProducts(0), numberOfCompletedOrders(0), id(++idGenerator)
{
	for(int i = 0; i < 5; i++)
		productsPrices[i] = DEFAULT_PRODUCT_MANUFACTURING_COST + SimulationManager::randomNumberGenerator(0.0, DEFAULT_PRODUCT_MANUFACTURING_COST);
}

Producer::~Producer(){

}

Factory Producer::buildFactory(){
	return Factory();
}


void Producer::realizeOrders()
{
	vector<Order>::iterator oIt = orders.begin();
	vector<Product>::iterator pIt = (*oIt).getBeginIterator();

	for(int i = 0; i < factories.size(); i++)
	{
		switch(factories[i].getState())
		{
		case READY : 
			if((*pIt).getCompletnessFactor() == 0.0)
				if(!payForProduct((*pIt).getProductType())) return;

			if(factories[i].manufacture(&(*pIt)) < 1.0)
				factories[i].setState(RUNNING);

			pIt++;
			break;

		case RUNNING :
			if(factories[i].manufacture(&(*pIt)) == 1.0)
				factories[i].setState(READY);

			break;

		case IDLE : 
			if((*pIt).getCompletnessFactor() == 0.0)
			{
				if(!payFactoryStartUp()) return;
				if(!payForProduct((*pIt).getProductType())) return;
			}

			factories[i].manufacture(&(*pIt));
			pIt++;
			break;
		}

		if(pIt == (*oIt).getEndIterator())
		{
			oIt++;
			if(oIt == orders.end())
			{
				i++;
				for(; i < factories.size(); i++)
				{
					switch(factories[i].getState())
					{
					case READY : 
						factories[i].setState(IDLE);
						factories[i].incIdleTime();
						break;

					case RUNNING :
						if(factories[i].manufacture(&(*pIt)) == 1.0)
							factories[i].setState(READY);
						break;

					case IDLE : 
							factories[i].incIdleTime();
						break;
					}
				}

				return;
			}
			pIt = (*oIt).getBeginIterator();
		}
	}
}

void Producer::receiveCash(double cash)
{
	if(cash < 0) return;
	this->cash += cash;

}

double Producer::getCash()
{
	return cash;
}

double Producer::getProductPrice(int productType)
{
	return productsPrices[productType];
}

int Producer::getID()
{
	return id;
}

bool Producer::acceptOrder(Order & order)
{
	if(numberOfProducts + order.getNumberOfProducts() < threshold) 
	{
		orders.push_back(order);
		return true;
	}

	return false;
}

int Producer::getNumberOfCompletedOrders()
{
	return numberOfCompletedOrders;
}

int Producer::getNumberOfFactories()
{
	return factories.size();
}

int Producer::getNumberOfOrders()
{
	return orders.size();
}

Factory Producer::getFactory(int index)
{
	return factories[index];
}

void Producer::payForFactories()
{
	cash -= factories.size() * Factory::getRunningCost();
}

bool Producer::payForProduct(int productType)
{
	double tmp = cash;
	cash -= getProductPrice(productType);

	if(cash < 0.0) 
	{
		cash = tmp;
		return false;
	}

	return true;
}

bool Producer::payFactoryStartUp()
{
	double tmp = cash;
	cash -= Factory::getFactoryStartUpCost();

	if(cash < 0.0) 
	{
		cash = tmp;
		return false;
	}

	return true;
}