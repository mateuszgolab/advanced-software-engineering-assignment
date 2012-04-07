#include<iostream>
#include"SimulationManager.h"
#include"SimulationPresenter.h"

using namespace std;

int main(int argc, char *argv[])
{
	Model model;
	// set parameters
	SimulationManager manager(model);
	manager.initializeModel();
	manager.startSimulation();

	SimulationPresenter presenter(model);

	int bankruptProducerID = 0;

	while(true)
	{
		int productType = manager.chooseProductType();
		manager.producersPayments();
		bankruptProducerID = manager.getBankruptProducer();
		
		if(bankruptProducerID > 0)
		{
			presenter.showBankruptcy(bankruptProducerID);
			return 0;
		}
		
		manager.findOffers(productType);
		manager.informConsumers(productType);
		manager.realizeOrders();
		manager.transferSalaries();
		presenter.showSimulationState();
		manager.nextCycle();
	}

	return 0;
}