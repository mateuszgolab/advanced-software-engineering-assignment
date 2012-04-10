///////////////////////////////////////////////////////////
//  SimulationManager.cpp
//  Implementation of the Class SimulationManager
//  Created on:      03-04-2012 23:54:59
//  Original author: Mateusz Golab
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

SimulationManager::SimulationManager(Model& model) : model(model), currentProductType(0)
{
	srand(time(NULL));
}

SimulationManager::SimulationManager() : currentProductType(0)
{
	srand(time(NULL));
}

SimulationManager::~SimulationManager()
{
	producers.clear();
	consumers.clear();
	offers.clear();
	cycle = 1;
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
		it->increasePrices(randomNumberGenerator(1.0, 5.0));
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

void SimulationManager::initializeModel(Model& model)
{
	this->model = model;
	producers.reserve(model.getNumberOfProducers());
	for(int i = 0; i < model.getNumberOfProducers(); i++)
	{
		producers.push_back(Producer(model.getCashPerProducer(), model.getQueueOrdersThreshold(), model.getProductCosts(), model.getProductLengths()));
	}

	consumers.reserve(model.getNumberOfConsumers());
	for(int i = 0; i < model.getNumberOfConsumers(); i++)
		consumers.push_back(Consumer(model.getCashPerConsumer(), model.getConsumerSalary()));

	Factory::setRunningCost(model.getFactoryRunningCost());
	Factory::setConstructionCost(model.getFactoryConstructionCost());
	Factory::setIdleStartUpCost(model.getIdleFactoryStartupCost());
}

void SimulationManager::initializeModel()
{
	producers.reserve(model.getNumberOfProducers());
	for(int i = 0; i < model.getNumberOfProducers(); i++)
	{
		producers.push_back(Producer(model.getCashPerProducer(), model.getQueueOrdersThreshold(), model.getProductCosts(), model.getProductLengths()));
	}

	consumers.reserve(model.getNumberOfConsumers());
	for(int i = 0; i < model.getNumberOfConsumers(); i++)
		consumers.push_back(Consumer(model.getCashPerConsumer(), model.getConsumerSalary()));

	Factory::setRunningCost(model.getFactoryRunningCost());
	Factory::setConstructionCost(model.getFactoryConstructionCost());
	Factory::setIdleStartUpCost(model.getIdleFactoryStartupCost());
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
	return getProducer(order.getProducerID()).acceptOrder(order);
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

Producer& SimulationManager::getProducer(int id)
{
	int index = id - producers[0].getID();
	if(index < 0) index = 0;
	return producers[index];
}

Consumer& SimulationManager::getConsumer(int id)
{
	int index = id - consumers[0].getID();
	if(index < 0) index = 0;
	return consumers[index];
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
		it->payForFactories();
	}
}

void SimulationManager::transaction(int producerID, int consumerID, double cash)
{
	getConsumer(consumerID).payProducer(cash);
	getProducer(producerID).receiveCash(cash);
}

Model& SimulationManager::getModel()
{
	return model;
}