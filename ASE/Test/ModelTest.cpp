#include "gtest/gtest.h"
#include "Model.h"

class ModelTest : public ::testing::Test
{
protected :
	Model m;

	ModelTest() 
	{
	}
};

TEST_F(ModelTest, customerCashTest)
{
	EXPECT_EQ(DEFAULT_CONSUMER_CASH, m.getCashPerConsumer());
	m.setConsumerCash(1000.0, 0.0);
	EXPECT_EQ(1000.0, m.getCashPerConsumer());
}

TEST_F(ModelTest, producerCashTest)
{
	EXPECT_EQ(DEFAULT_PRODUCER_CASH, m.getCashPerProducer());
	m.setProducerCash(1000.0, 0.0);
	EXPECT_EQ(1000.0, m.getCashPerProducer());
}

TEST_F(ModelTest, factoryConstructionCostTest)
{
	EXPECT_EQ(DEFAULT_FACTORY_CONSTRUCTION_COST, m.getFactoryConstructionCost());
	m.setFactoryConstructionCost(1000.0);
	EXPECT_EQ(1000.0, m.getFactoryConstructionCost());
}

TEST_F(ModelTest, factoryRunningCostTest)
{
	EXPECT_EQ(DEFAULT_FACTORY_RUNNING_COST, m.getFactoryRunningCost());
	m.setFactoryRunningCost(1000.0);
	EXPECT_EQ(1000.0, m.getFactoryRunningCost());
}

TEST_F(ModelTest, factoryStartupCostTest)
{
	EXPECT_EQ(DEFAULT_IDLE_FACTORY_STARTUP_COST, m.getIdleFactoryStartupCost());
	m.setIdleFactoryStartUpCost(1000.0);
	EXPECT_EQ(1000.0, m.getIdleFactoryStartupCost());
}

TEST_F(ModelTest, numberOfConsumersTest)
{
	EXPECT_EQ(DEFAULT_NUMBER_OF_CONSUMERS, m.getNumberOfConsumers());
	m.setNumberOfConsumers(1000);
	EXPECT_EQ(1000, m.getNumberOfConsumers());
}

TEST_F(ModelTest, numberOfProducersTest)
{
	EXPECT_EQ(DEFAULT_NUMBER_OF_PRODUCERS, m.getNumberOfProducers());
	m.setNumberOfProducers(1000);
	EXPECT_EQ(1000, m.getNumberOfProducers());
}

TEST_F(ModelTest, thresholdTest)
{
	EXPECT_EQ(DEFAULT_QUEUE_THRESHOLD, m.getQueueOrdersThreshold());
	m.setQueueOrdersThreshold(1000);
	EXPECT_EQ(1000, m.getQueueOrdersThreshold());
}









	
	//void setProductManufacturingCost(std::vector<double> costs);
	//void setProductManufacturingTime(std::vector<int> cycles);
	//double getConsumerSalary();

