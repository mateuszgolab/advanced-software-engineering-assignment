///////////////////////////////////////////////////////////
//  Producer.cpp
//  Implementation of the Class Producer
//  Created on:      03-kwi-2012 23:54:54
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Producer.h"


using namespace std;

int Producer::idGenerator = 0;
int Producer::threshold = 50;

Producer::Producer(double cash) : cash(cash), numberOfProducts(0), numberOfCompletedOrders(0)
{
	id = ++idGenerator;
}

Producer::~Producer(){

}

Factory Producer::buildFactory(){
	return Factory();
}

void Producer::payFactoryStartUp(){

}

void Producer::realizeOrders()
{
	vector<Order>::iterator oIt = orders.begin();
	vector<Product>::iterator pIt = (*oIt).getProductIterator();

	for(int i = 0; i < factories.size(); i++)
	{
		switch(factories[i].getState())
		{
			case INIT : 
				if(cash <= factories[i].getRunningCost())
				factories[i].manufacture(*pIt);
				break;
			case IDLE : 
				factories[i].manufacture(*pIt);
				break;
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