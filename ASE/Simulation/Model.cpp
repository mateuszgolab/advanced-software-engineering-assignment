///////////////////////////////////////////////////////////
//  Model.cpp
//  Implementation of the Class Model
//  Created on:      03-kwi-2012 23:55:05
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Model.h"


using namespace std;

Model::Model() : cashPerCustomer(DEFAULT_CUSTOMER_CASH), cashPerProducer(DEFAULT_PRODUCER_CASH), consumerCashOscilation(DEFAULT_CASH_OSCILATION), numberOfCustomers(DEFAULT_NUMBER_OF_CUSTOMERS), 
	numberOfProducers(DEFAULT_NUMBER_OF_PRODUCERS), consumerSalary(DEFAULT_CUSTOMER_SALARY), factoryConstructionCost(DEFAULT_FACTORY_CONSTRUCTION_COST), factoryRunningCost(DEFAULT_FACTORY_RUNNING_COST), 
	idleFactoryStartUpCost(DEFAULT_IDLE_FACTORY_STARTUP_COST), producerCashOscilation(DEFAULT_CASH_OSCILATION), queueOrdersThreshold(DEFAULT_QUEUE_THRESHOLD)
{
	
	
}

Model::~Model(){

}

void Model::setCustomerCash(double cash, double var){

}

void Model::setFactoryConstructionCost(double cost){

}

void Model::setFactoryRunningCost(double cost){

}

void Model::setIdleFactoryStartUpCost(double cost){

}

void Model::setNumberOfCustomers(int numberOfCustomers){

}

void Model::setNumberOfProducers(int numberOfProducers){

}

void Model::setProducerCash(double cash, double var){

}

void Model::setProductManufacturingCost(vector<double> costs){

}

void Model::setProductManufacturingTime(vector<int> cycles){

}

void Model::setQueueOrdersThreshold(int threshold){

}

double Model::getCashPerConsumer()
{
	return cashPerCustomer;
}

double Model::getCashPerProducer()
{
	return cashPerProducer;
}

double Model::getConsumerSalary()
{
	return consumerSalary;
}

int Model::getNumberOfCustomers()
{
	return numberOfCustomers;
}

int Model::getNumberOfProducers()
{
	return numberOfProducers;
}

double Model::getFactoryConstructionCost()
{
	return factoryConstructionCost;
}

double Model::getFactoryRunningCost()
{
	return factoryRunningCost;
}