#include "gtest/gtest.h"
#include "SimulationPresenter.h"
#include <fstream>
using namespace std;

class SimulationPresenterTest : public ::testing::Test
{
protected :
	SimulationPresenter p;
	SimulationManager m;

	SimulationPresenterTest() : p(m, "test.txt")
	{

	}
};


TEST_F(SimulationPresenterTest, screenOutputTest)
{


	try
	{
			m.initializeModel();
	ofstream os;
		p.showBankruptcy(os, 1);
		p.showSimulationState(os);
	}
	catch(...)
	{
		EXIT_FAILURE;
	}
}


TEST_F(SimulationPresenterTest, fileOutputTest)
{
	try
	{
		m.initializeModel();
		p.saveResults();
		ifstream f("test.txt");

		EXPECT_TRUE(f);
	}
	catch(...)
	{
		EXIT_FAILURE;
	}
	
}