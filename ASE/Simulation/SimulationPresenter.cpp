///////////////////////////////////////////////////////////
//  SimulationPresenter.cpp
//  Implementation of the Class SimulationPresenter
//  Created on:      06-kwi-2012 16:09:44
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "SimulationPresenter.h"
#include <iostream>
#include <fstream>
#include "SimulationManager.h"


using namespace std;


SimulationPresenter::SimulationPresenter(const SimulationManager & manager) : manager(manager)
{
}

SimulationPresenter::~SimulationPresenter(){

}

void SimulationPresenter::showSimulationState(ostream & os)
{
	os<<"Cycle : "<<SimulationManager::getCycleNumber()<<endl;
	int n = manager.getNumberOfProducers();

	for(int i = 1; i <= n; i++)
	{
		Producer producer = manager.getProducer(i);
		os<<"Producer id : "<<producer.getID()<<endl;
		os<<"Number of orders : "<<producer.getNumberOfOrders()<<endl;
		os<<"Number of orders completed : "<<producer.getNumberOfCompletedOrders()<<endl;
		os<<"Number of factories : "<<producer.getNumberOfFactories()<<endl;
		os<<"Cash reserves : "<<producer.getCash()<<endl<<endl;
	}

	os<<"Average cash reserves for all the consumers : "<<manager.getConsumersAverageCash()<<endl<<endl;
	os<<"----------------------------------------------------------"<<endl;

}

void SimulationPresenter::showBankruptcy(ostream & os, int producerID)
{
	os<<"Producer "<<producerID<<" is bankrupt"<<endl;
	os<<"Simulation ended"<<endl;
}

void SimulationPresenter::saveResults(string fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	showSimulationState(myfile);
	myfile.close();
}
