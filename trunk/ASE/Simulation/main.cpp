#include<iostream>
#include"SimulationManager.h"
#include"SimulationPresenter.h"

using namespace std;

int main()
{
	Model model;

	SimulationManager manager(model);
	SimulationPresenter presenter(manager, "results.txt");
	if(!presenter.setParameters(cout)) return 0;
	manager.initializeModel(presenter.getModel());
	
	int bankruptProducerID = 0;

	while(true)
	{
		int productType = manager.chooseProductType();
		manager.producersPayments();
		bankruptProducerID = manager.getBankruptProducer();
		
		if(bankruptProducerID > 0)
		{
			presenter.showBankruptcy(std::cout, bankruptProducerID);
			cout<<"press any key to finish"<<endl;
			getchar();
			getchar();
			return 0;
		}
		
		manager.findOffers(productType);
		manager.informConsumers(productType);
		manager.realizeOrders();
		manager.transferSalaries();
		presenter.showSimulationState(std::cout);
		presenter.saveResults();
		manager.demolishUnusedFactories();
		manager.nextCycle();

	
	}

	

	return 0;
}