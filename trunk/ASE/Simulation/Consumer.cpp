///////////////////////////////////////////////////////////
//  Consumer.cpp
//  Implementation of the Class Consumer
//  Created on:      03-kwi-2012 23:54:57
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Consumer.h"
#include "SimulationManager.h"


int Consumer::idGenerator = 0;

Consumer::Consumer(double cash, double salary) : cash(cash), salary(salary) , id(++idGenerator)
{

}



Consumer::~Consumer(){

}





Order Consumer::makeOrder(int productType)
{
	Offer offer = SimulationManager::getBestOffer(productType);
	int n = cash / offer.getPrice();

	return Order(id, offer.getProducerID(), n * offer.getPrice(), n , productType);
}


void Consumer::payProducer(double price, int producerID){

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

