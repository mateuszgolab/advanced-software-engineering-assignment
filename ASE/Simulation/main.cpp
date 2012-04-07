#include<iostream>
#include"SimulationManager.h"
#include"SimulationPresenter.h"

using namespace std;

int main(int argc, char *argv[])
{
	Model model;
	// set parameters
	SimulationManager simulationManager(model);
	simulationManager.initializeModel();
	simulationManager.startSimulation();

	SimulationPresenter presenter(model);

	while(!simulationManager.isAnyProducerBankrupt())
	{
		int productType = simulationManager.chooseProductType();
		simulationManager.informCustomers(productType);

		simulationManager.transferSalaries();
		presenter.showSimulationState();
	}

	return 0;
}