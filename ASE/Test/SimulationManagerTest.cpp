#include "gtest/gtest.h"
#include "SimulationManager.h"

class SimulationManagerTest : public ::testing::Test
{
protected :
	SimulationManager manager;
};


TEST_F(SimulationManagerTest, initializeModelTest)
{

}

TEST_F(SimulationManagerTest, demolishFactoryTest)
{

}

TEST_F(SimulationManagerTest, getBestOfferTest)
{
	manager.initializeModel();

}