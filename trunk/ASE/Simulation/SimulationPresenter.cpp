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


SimulationPresenter::SimulationPresenter(const Model & model) : model(model)
{
}



SimulationPresenter::~SimulationPresenter(){

}





void SimulationPresenter::showSimulationState()
{
	cout<<"Cycle : "<<SimulationManager::getCycleNumber()<<endl;
	//for(int i = 0; i < SimulationManager::getN


}

void SimulationPresenter::showBankruptcy(int producerID)
{

}