///////////////////////////////////////////////////////////
//  SimulationPresenter.cpp
//  Implementation of the Class SimulationPresenter
//  Created on:      06-kwi-2012 16:09:44
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "SimulationPresenter.h"
#include <iostream>
#include "SimulationManager.h"


using namespace std;


SimulationPresenter::SimulationPresenter(const SimulationManager & manager) : manager(manager)
{
}

SimulationPresenter::~SimulationPresenter(){

}

void SimulationPresenter::showSimulationState()
{
	cout<<"Cycle : "<<SimulationManager::getCycleNumber()<<endl;
	int n = manager.getNumberOfProducers();

	for(int i = 0; i < n; i++)
	{
		Producer producer = manager.getProducer(i);
		cout<<"Producer id : "<<producer.getID()<<endl;
		cout<<"Number of orders : "<<producer.getNumberOfOrders()<<endl;
		cout<<"Number of orders completed : "<<producer.getNumberOfCompletedOrders()<<endl;
		cout<<"Number of factories : "<<producer.getNumberOfFactories()<<endl;
		cout<<"Cash reserves : "<<producer.getCash()<<endl<<endl;
	}

	cout<<"Average cash reserves for all the consumers : "<<manager.getConsumersAverageCash()<<endl<<endl;

}

void SimulationPresenter::showBankruptcy(int producerID)
{
	cout<<"Producer "<<producerID<<" is bankrupt"<<endl;
	cout<<"Simulation ended"<<endl;
}