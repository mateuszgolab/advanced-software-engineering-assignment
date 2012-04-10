///////////////////////////////////////////////////////////
//  SimulationPresenter.h
//  Implementation of the Class SimulationPresenter
//  Created on:      06-04-2012 16:09:44
//  Original author: Mateusz Golab
///////////////////////////////////////////////////////////

#if !defined(EA_033FCF20_B358_49f8_8420_17D9995BBAFB__INCLUDED_)
#define EA_033FCF20_B358_49f8_8420_17D9995BBAFB__INCLUDED_

#include <ostream>
#include "SimulationManager.h"

class SimulationPresenter
{
public:
	SimulationPresenter(SimulationManager & manager, std::string fileName);
	virtual ~SimulationPresenter();

	void showSimulationState(std::ostream & os);
	void showBankruptcy(std::ostream & os, int producerID);
	void saveResults();
	bool setParameters(std::ostream & os);
	void showWelcome(std::ostream &os);
	Model & getModel();

private:
	SimulationManager manager;
	std::string fileName;

};
#endif // !defined(EA_033FCF20_B358_49f8_8420_17D9995BBAFB__INCLUDED_)
