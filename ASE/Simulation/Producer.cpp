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

Producer::Producer(double cash) : cash(cash), numberOfProducts(0), numberOfCompletedOrders(0), id(++idGenerator), iteratorsInitialized(false)
{
	for(int i = 0; i < 5; i++)
		productsPrices[i] = DEFAULT_PRODUCT_MANUFACTURING_COST + SimulationManager::randomNumberGenerator(1.0, DEFAULT_PRODUCT_MANUFACTURING_COST);

	factories.push_back(Factory());
	
}

Producer::~Producer(){

}

bool Producer::buildFactory(){
	if(cash > Factory::getConstructionCost())
	{
		cash -= Factory::getConstructionCost();
		factories.push_back(Factory());
		return true;
	}
	return false;
}

void Producer::realizeOrders()
{
	for(int i = 0; i < factories.size(); i++)
	{
		if(ordersIterator != orders.end())
		{
			switch(factories[i].getState())
			{
			case READY : 
				if(!payForProduct((*productIterator).getProductType())) return;

				if(factories[i].manufacture(&(*productIterator)) < 1.0)
					factories[i].setState(RUNNING);

				productIterator++;
				break;

			case RUNNING :
				if(factories[i].manufacture() == 1.0)
					factories[i].setState(READY);
				break;

			case IDLE : 
				if(!payFactoryStartUp()) return;
				if(!payForProduct((*productIterator).getProductType())) return;
				factories[i].manufacture(&(*productIterator));
				productIterator++;
				break;
			}

			if(productIterator == (*ordersIterator).getEndIterator())
			{
				ordersIterator++;
				if(ordersIterator != orders.end())
					productIterator = (*ordersIterator).getBeginIterator();
			}
		}
		else
		{
			switch(factories[i].getState())
			{
			case READY : 
					factories[i].setState(IDLE);
					factories[i].incIdleTime();
				break;

			case RUNNING :
				if(factories[i].manufacture() == 1.0)
					factories[i].setState(READY);
				break;

			case IDLE : 
				factories[i].incIdleTime();
				break;
			}
		}
	}

	while(ordersIterator != orders.end())
	{
		if(!buildFactory()) return;

		if(productIterator == (*ordersIterator).getEndIterator())
		{
			ordersIterator++;
			if(ordersIterator != orders.end())
				productIterator = (*ordersIterator).getBeginIterator();
		}
	}
}

void Producer::finalizeOrders()
{
	for(vector<Order>::iterator it = orders.begin(); it != orders.end(); it++)
	{
		if((*it).isCompleted())
		{
			SimulationManager::transaction((*it).getProducerID(), (*it).getConsumerID(), (*it).getCost());
			orders.erase(it);
			numberOfCompletedOrders++;
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
		if(!iteratorsInitialized)
		{
			ordersIterator = orders.begin();
			productIterator = ordersIterator->getBeginIterator();
			iteratorsInitialized = true;
		}
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

Factory& Producer::getFactory(int index)
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

void Producer::demolishUnusedFactories()
{
	vector<Factory>::iterator it = factories.begin();
	while(it != factories.end())
	{
		if((*it).getIdleTime() > 50)
		{
			it = factories.erase(it);
		}
		else it++;
	}
}

void Producer::increasePrices(double percentage)
{
	for(int i = 0; i < 5; i++)
	{
		productsPrices[i] *= (1.0 + percentage/100);
	}
}