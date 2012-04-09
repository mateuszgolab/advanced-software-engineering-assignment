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
vector<Consumer> SimulationManager::consumers;
int SimulationManager::cycle = 1;

SimulationManager::SimulationManager(Model& model) : model(model)
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

void SimulationManager::demolishUnusedFactories()
{
	for(vector<Producer>::iterator it = producers.begin(); it != producers.end(); it++)
	{
		it->demolishUnusedFactories();
	}
}

void SimulationManager::increasePrices()
{
	for(vector<Producer>::iterator it = producers.begin(); it != producers.end(); it++)
	{
		it->increasePrices(randomNumberGenerator(0.0, 5.0));
	}
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
		offers.push_back(Offer(producers[i].getID(), producers[i].getProductPrice(productType)));
	}

	sort(offers.begin(), offers.end(), offer);
}

void SimulationManager::initializeModel()
{
	producers.reserve(model.getNumberOfProducers());
	for(int i = 0; i < model.getNumberOfProducers(); i++)
	{
		producers.push_back(Producer(model.getCashPerProducer()));
		producers[i].buildFactory();
	}

	consumers.reserve(model.getNumberOfCustomers());
	for(int i = 0; i < model.getNumberOfCustomers(); i++)
		consumers.push_back(Consumer(model.getCashPerConsumer(), model.getConsumerSalary()));

	Factory::setRunningCost(model.getFactoryRunningCost());
	Factory::setConstructionCost(model.getFactoryConstructionCost());
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
		if(consumers[i].getState() == NOTHING_ORDERED)
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
	if(!(cycle % 10))
		increasePrices();
	cycle++;
}

double SimulationManager::getConsumersAverageCash()
{
	double cash = 0.0;
	for(int i = 0; i < consumers.size(); i++)
	{
		cash += consumers[i].getCash();
	}

	return cash / consumers.size();
}

int SimulationManager::getNumberOfConsumers()
{
	return consumers.size();
}

int SimulationManager::getNumberOfProducers()
{
	return producers.size();
}

Producer SimulationManager::getProducer(int index) const
{
	return producers[index];
}

void SimulationManager::realizeOrders()
{
	for(int i = 0; i < producers.size(); i++)
	{
		producers[i].realizeOrders();
		producers[i].finalizeOrders();
	}
}

void SimulationManager::producersPayments()
{
	vector<Producer>::iterator it = producers.begin();

	for(;it != producers.end(); it++)
	{
		(*it).payForFactories();
	}
}

void SimulationManager::transaction(int producerID, int consumerID, double cash)
{
	consumers[consumerID - 1].payProducer(cash);
	producers[producerID - 1].receiveCash(cash);
}