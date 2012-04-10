///////////////////////////////////////////////////////////
//  SimulationPresenter.cpp
//  Implementation of the Class SimulationPresenter
//  Created on:      06-04-2012 16:09:44
//  Original author: Mateusz Golab
///////////////////////////////////////////////////////////

#include "SimulationPresenter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "SimulationManager.h"


using namespace std;


SimulationPresenter::SimulationPresenter(SimulationManager & manager, string fileName) : manager(manager), fileName(fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	myfile.close();
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
	os<<"Simulation ended after "<<manager.getCycleNumber()<<" cycles"<<endl;
}

void SimulationPresenter::saveResults()
{
	ofstream myfile;
	myfile.open(fileName, fstream::app);
	showSimulationState(myfile);
	myfile.close();
}

bool SimulationPresenter::setParameters(ostream & os)
{
	int param;
	double input;
	vector<double> productCosts;
	vector<double> productLengths;

	for(int i = 0; i < 5; i++)
	{
		productCosts.push_back(DEFAULT_PRODUCT_MANUFACTURING_COST);
		productLengths.push_back(DEFAULT_PRODUCT_MANUFACTURING_LENGTH);
	}

	while(true)
	{
		os<<"Choose parameter to set : "<<endl;
		os<<"1 - Number of consumers"<<endl;
		os<<"2 - Number of producers"<<endl;
		os<<"3 - Initial consumer's cash"<<endl;
		os<<"4 - Initial producer's cash"<<endl;
		os<<"5 - Product type 1 manufacturing cost"<<endl;
		os<<"6 - Product type 2 manufacturing cost"<<endl;
		os<<"7 - Product type 3 manufacturing cost"<<endl;
		os<<"8 - Product type 4 manufacturing cost"<<endl;
		os<<"9 - Product type 5 manufacturing cost"<<endl;
		os<<"10 - Product type 1 manufacturing length"<<endl;
		os<<"11 - Product type 2 manufacturing length"<<endl;
		os<<"12 - Product type 3 manufacturing length"<<endl;
		os<<"13 - Product type 4 manufacturing length"<<endl;
		os<<"14 - Product type 5 manufacturing length"<<endl;
		os<<"15 - Factory construction cost"<<endl;
		os<<"16 - Factory running cost"<<endl;
		os<<"17 - Idle factory start-up cost"<<endl;
		os<<"18 - Customer's salary"<<endl;
		os<<"19 - Order's queue threshold"<<endl;
		os<<"------------------------------------------"<<endl;
		os<<"20 - Start simulation"<<endl;
		os<<"21 - Close program"<<endl;

		cin>>param;
		if(param == 21) return false;
		else if(param == 20)
		{
			manager.getModel().setProductManufacturingCost(productCosts);
			manager.getModel().setProductManufacturingTime(productLengths);
			return true;
		}
		

		if(param > 0 && param < 20)
		{
			cin>>input;

			switch(param)
			{
				case 1 :
					manager.getModel().setNumberOfConsumers(input);
				break;

				case 2 :
					manager.getModel().setNumberOfProducers(input);
				break;

				case 3 :
					manager.getModel().setConsumerCash(input);
				break;

				case 4 :
					manager.getModel().setProducerCash(input);
				break;

				case 5 :
				case 6 :
				case 7 :
				case 8 :
				case 9 :
					productCosts[param-5] = input;
				break;

				case 10 :
				case 11 :
				case 12 :
				case 13 :
				case 14 :
					productLengths[param - 10] = input;
				break;

				case 15 :
					manager.getModel().setFactoryConstructionCost(input);
				break;

				case 16 :
					manager.getModel().setFactoryRunningCost(input);
				break;

				case 17 :
					manager.getModel().setIdleFactoryStartUpCost(input);
				break;

				case 18 :
					manager.getModel().setConsumerSalary(input);
				break;

				case 19 :
					manager.getModel().setQueueOrdersThreshold(input);
				break;
			}
		}
	}
}

void SimulationPresenter::showWelcome(ostream & os)
{
	os<<"Producers-Consumers Economic Relationship Model Simulation v1.0"<<endl<<endl;
}


Model & SimulationPresenter::getModel()
{
	return manager.getModel();
}
