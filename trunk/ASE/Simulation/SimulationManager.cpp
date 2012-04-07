///////////////////////////////////////////////////////////
//  SimulationManager.cpp
//  Implementation of the Class SimulationManager
//  Created on:      03-kwi-2012 23:54:59
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "SimulationManager.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

vector<Producer> SimulationManager::producers;
vector<Offer> SimulationManager::offers;
int SimulationManager::cycle = 1;

SimulationManager::SimulationManager(Model& model)
{
	srand(time(NULL));

}

SimulationManager::SimulationManager()
{
	srand(time(NULL));
}

SimulationManager::~SimulationManager()
{

}

void SimulationManager::checkFactoriesIdleTime(){

}

void SimulationManager::demolishFactory(int factoryID){

}

void SimulationManager::increasePrices(double val){

}

int SimulationManager::getBankruptProducer()
{
	for(int i = 0; i < producers.size(); i++)
	{
		if(producers[i].getCash() < producers[i].getProductPrice(currentProductType))
			return producers[i].getID();
	}

	return -1;

}

void SimulationManager::performNextCycle(){

}

void SimulationManager::saveResults(string fileName){

}

void SimulationManager::showResults(){

}

void SimulationManager::startSimulation(){

}

vector<Offer> SimulationManager::getOffers()
{
	return offers;
}

void SimulationManager::findOffers(int productType)
{
	offers.clear();
	Offer offer;

	for(int i = 0; i < producers.size(); i++)
	{
		offers[i] = Offer(producers[i].getID(), producers[i].getProductPrice(productType));
	}

	sort(offers.begin(), offers.end(), offer);
}

Product SimulationManager::createProduct(int type)
{
	return Product();
}

void SimulationManager::initializeModel()
{
	producers.reserve(model.getNumberOfProducers());
	for(int i = 0; i < producers.size(); i++)
	{
		producers[i] = Producer(model.getCashPerProducer());
		producers[i].buildFactory();
	}

	consumers.reserve(model.getNumberOfCustomers());
	for(int i = 0; i < consumers.size(); i++)
		consumers[i] = Consumer(model.getCashPerConsumer(), model.getConsumerSalary());
}

void SimulationManager::transferSalaries()
{
	for(int i = 0; i < consumers.size(); i++)
		consumers[i].receiveSalary();
}

void SimulationManager::informConsumers(int productType)
{
	for(int i = 0; i < consumers.size(); i++)
	{
		if(consumers[i].getState() == NOT_ORDERED)
		{
			consumers[i].makeOrder(productType);	
		}
	}
}

int SimulationManager::chooseProductType()
{
	currentProductType = rand() % 5;
	return currentProductType;
}

double SimulationManager::randomNumberGenerator(double low, double high)
{
	double range = high - low;
	double num = fmod(rand(), range) + low;
	return num;
}

bool SimulationManager::isProducerInterested(Order order)
{
	int index = order.getID() - 1;
	return producers[index].acceptOrder(order);
}

int SimulationManager::getCycleNumber()
{
	return cycle;
}

void SimulationManager::nextCycle()
{
	cycle++;
}