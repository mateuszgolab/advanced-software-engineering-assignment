///////////////////////////////////////////////////////////
//  SimulationPresenter.h
//  Implementation of the Class SimulationPresenter
//  Created on:      06-kwi-2012 16:09:44
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_033FCF20_B358_49f8_8420_17D9995BBAFB__INCLUDED_)
#define EA_033FCF20_B358_49f8_8420_17D9995BBAFB__INCLUDED_

#include <ostream>
#include "SimulationManager.h"

class SimulationPresenter
{

public:
	SimulationPresenter(const SimulationManager & manager);
	virtual ~SimulationPresenter();

	void showSimulationState(std::ostream & os);
	void showBankruptcy(std::ostream & os, int producerID);
	void saveResults(std::string fileName);

private:
	SimulationManager manager;

};
#endif // !defined(EA_033FCF20_B358_49f8_8420_17D9995BBAFB__INCLUDED_)
