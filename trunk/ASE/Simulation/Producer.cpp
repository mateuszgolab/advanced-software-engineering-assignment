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

Producer::Producer(double cash) : cash(cash), numberOfProducts(0), numberOfCompletedOrders(0), id(++idGenerator), ordersIterator(0), productIterator(0)
{
	for(int i = 0; i < 5; i++)
		productsPrices[i] = DEFAULT_PRODUCT_MANUFACTURING_COST + SimulationManager::randomNumberGenerator(1.0, DEFAULT_PRODUCT_MANUFACTURING_COST);

	factories.push_back(Factory());
}

Producer::~Producer(){

}

bool Producer::buildFactory()
{
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
	int i;
	for(i = 0; i < factories.size(); i++)
	{
		if(ordersIterator < orders.size())
		{
			switch(factories[i].getState())
			{
			case READY : 
				if(!payForProduct(getProduct().getProductType())) return;

				if(factories[i].manufacture(&getProduct()) < 1.0)
					factories[i].setState(RUNNING);

				productIterator++;
				break;

			case RUNNING :
				if(factories[i].manufacture() == 1.0)
					factories[i].setState(READY);
				break;

			case IDLE : 
				if(!payFactoryStartUp()) return;
				if(!payForProduct(getProduct().getProductType())) return;
				if(factories[i].manufacture(&getProduct()) < 1.0)
					factories[i].setState(RUNNING);

				productIterator++;
				break;
			}

			if(productIterator == orders[ordersIterator].getNumberOfProducts())
			{
				ordersIterator++;
				if(ordersIterator < orders.size())
					productIterator = 0;
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

	while(ordersIterator < orders.size())
	{
		if(!buildFactory()) return;

		if(!payForProduct(getProduct().getProductType())) return;

		if(factories[i].manufacture(&getProduct()) < 1.0)
			factories[i].setState(RUNNING);

		productIterator++;
		i++;

		if(productIterator == orders[ordersIterator].getNumberOfProducts())
		{
			ordersIterator++;
			if(ordersIterator < orders.size())
				productIterator = 0;
		}
	}
}

void Producer::finalizeOrders()
{
	vector<Order>::iterator it = orders.begin();
	while(it != orders.end())
	{
		if(it->isCompleted())
		{
			SimulationManager::transaction(it->getProducerID(), it->getConsumerID(), it->getCost());
			numberOfProducts -= it->getNumberOfProducts();
			it = orders.erase(it);
			numberOfCompletedOrders++;
		}
		else it++;
	}
}

void Producer::receiveCash(double cash)
{
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
	if(numberOfProducts + order.getNumberOfProducts() <= threshold) 
	{
		orders.push_back(order);
		numberOfProducts += order.getNumberOfProducts();
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

Product& Producer::getProduct()
{
	return orders[ordersIterator].getProduct(productIterator);
}