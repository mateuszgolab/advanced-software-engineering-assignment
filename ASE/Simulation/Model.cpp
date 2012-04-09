///////////////////////////////////////////////////////////
//  Model.cpp
//  Implementation of the Class Model
//  Created on:      03-kwi-2012 23:55:05
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Model.h"


using namespace std;

Model::Model() : cashPerConsumer(DEFAULT_CONSUMER_CASH), cashPerProducer(DEFAULT_PRODUCER_CASH), consumerCashOscilation(DEFAULT_CASH_OSCILATION), numberOfConsumers(DEFAULT_NUMBER_OF_CONSUMERS), 
	numberOfProducers(DEFAULT_NUMBER_OF_PRODUCERS), consumerSalary(DEFAULT_CONSUMER_SALARY), factoryConstructionCost(DEFAULT_FACTORY_CONSTRUCTION_COST), factoryRunningCost(DEFAULT_FACTORY_RUNNING_COST), 
	idleFactoryStartUpCost(DEFAULT_IDLE_FACTORY_STARTUP_COST), producerCashOscilation(DEFAULT_CASH_OSCILATION), queueOrdersThreshold(DEFAULT_QUEUE_THRESHOLD)
{
	
	
}

Model::~Model(){

}

void Model::setConsumerCash(double cash, double var = 10.0)
{
	cashPerConsumer = cash;
}

void Model::setFactoryConstructionCost(double cost)
{
	factoryConstructionCost = cost;
}

void Model::setFactoryRunningCost(double cost)
{
	factoryRunningCost = cost;
}

void Model::setIdleFactoryStartUpCost(double cost)
{
	idleFactoryStartUpCost = cost;
}

void Model::setNumberOfConsumers(int numberOfConsumers)
{
	this->numberOfConsumers = numberOfConsumers;
}

void Model::setNumberOfProducers(int numberOfProducers)
{
	this->numberOfProducers = numberOfProducers;
}

void Model::setProducerCash(double cash, double var = 10.0)
{
	cashPerProducer = cash;
}

void Model::setProductManufacturingCost(vector<double> costs)
{
	
}

void Model::setProductManufacturingTime(vector<int> cycles)
{

}

void Model::setQueueOrdersThreshold(int threshold)
{
	queueOrdersThreshold = threshold;
}

double Model::getCashPerConsumer() const
{
	return cashPerConsumer;
}

double Model::getCashPerProducer() const
{
	return cashPerProducer;
}

double Model::getConsumerSalary() const
{
	return consumerSalary;
}

int Model::getNumberOfConsumers() const
{
	return numberOfConsumers;
}

int Model::getNumberOfProducers() const
{
	return numberOfProducers;
}

double Model::getFactoryConstructionCost() const
{
	return factoryConstructionCost;
}

double Model::getFactoryRunningCost() const
{
	return factoryRunningCost;
}

double Model::getIdleFactoryStartupCost() const
{
	return idleFactoryStartUpCost;
}

int Model::getQueueOrdersThreshold() const
{
	return queueOrdersThreshold;
}