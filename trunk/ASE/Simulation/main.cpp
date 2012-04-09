#include<iostream>
#include"SimulationManager.h"
#include"SimulationPresenter.h"

using namespace std;

int main()
{
	Model model;
	// set parameters
	SimulationManager manager(model);
	manager.initializeModel();

	SimulationPresenter presenter(manager);

	int bankruptProducerID = 0;

	while(true)
	{
		int productType = manager.chooseProductType();
		manager.producersPayments();
		bankruptProducerID = manager.getBankruptProducer();
		
		if(bankruptProducerID > 0)
		{
			presenter.showBankruptcy(std::cout, bankruptProducerID);
			return 0;
		}
		
		manager.findOffers(productType);
		manager.informConsumers(productType);
		manager.realizeOrders();
		manager.transferSalaries();
		presenter.showSimulationState(std::cout);
		manager.demolishUnusedFactories();
		manager.nextCycle();

	
	}

	return 0;
}