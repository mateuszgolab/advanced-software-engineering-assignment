///////////////////////////////////////////////////////////
//  Consumer.cpp
//  Implementation of the Class Consumer
//  Created on:      03-04-2012 23:54:57
//  Original author: Mateusz Golab
///////////////////////////////////////////////////////////

#include "Consumer.h"
#include "SimulationManager.h"

using namespace std;

int Consumer::idGenerator = 0;

Consumer::Consumer(double cash, double salary) : cash(cash), salary(salary) , id(++idGenerator), state(NOTHING_ORDERED)
{

}

Consumer::~Consumer(){

}

void Consumer::makeOrder(int productType)
{
	vector<Offer> offers = SimulationManager::getOffers();

	for(int i = 0; i < offers.size(); i++)
	{
		int n = cash / offers[i].getPrice();
		if(n <= 0) continue;
		Order order(id, offers[i].getProducerID(), n * offers[i].getPrice(), n , productType);
		if(SimulationManager::isProducerInterested(order)) 
		{
			state = PRODUCT_ORDERED;
			break;
		}
	}
}

void Consumer::payProducer(double price)
{
	cash -= price;
}

void Consumer::receiveSalary()
{
	cash += salary;
}

void Consumer::setSalary(double salary)
{
	this->salary = salary;
}

double Consumer::getCash()
{
	return cash;
}

ConsumerState Consumer::getState()
{
	return state;
}

int Consumer::getID()
{
	return id;
}
