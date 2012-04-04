///////////////////////////////////////////////////////////
//  SimulationManager.h
//  Implementation of the Class SimulationManager
//  Created on:      03-kwi-2012 23:54:59
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_C8DA3665_B677_453f_B292_9AA5F37D2A53__INCLUDED_)
#define EA_C8DA3665_B677_453f_B292_9AA5F37D2A53__INCLUDED_

#include "Model.h"

class SimulationManager
{

public:
	SimulationManager(Model& model);
	virtual ~SimulationManager();

	void checkFactoriesIdleTime();
	void demolishFactory(int factoryID);
	void increasePrices(double val);
	bool isAnyProducerBankrupt();
	void performNextCycle();
	void saveResults(std::string fileName);
	void showResults();
	void startSimulation();

private:
	Model model;

};
#endif // !defined(EA_C8DA3665_B677_453f_B292_9AA5F37D2A53__INCLUDED_)
