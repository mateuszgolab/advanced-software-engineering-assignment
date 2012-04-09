#include "gtest/gtest.h"
#include "SimulationManager.h"

class SimulationManagerTest : public ::testing::Test
{
protected :
	SimulationManager m;
};


TEST_F(SimulationManagerTest, initializeModelTest)
{
	EXPECT_EQ(0, m.getNumberOfConsumers());
	EXPECT_EQ(0, m.getNumberOfProducers());

	m.initializeModel();

	EXPECT_EQ(DEFAULT_NUMBER_OF_CONSUMERS, m.getNumberOfConsumers());
	EXPECT_EQ(DEFAULT_NUMBER_OF_PRODUCERS, m.getNumberOfProducers());
}

TEST_F(SimulationManagerTest, demolishFactoryTest)
{
	m.initializeModel();
	m.demolishUnusedFactories();
	
	EXPECT_EQ(1, m.getProducer(1).getNumberOfFactories());

	for(int i = 0; i < 51; i++)
		m.realizeOrders();

	m.demolishUnusedFactories();
	EXPECT_EQ(0, m.getProducer(1).getNumberOfFactories());
}

TEST_F(SimulationManagerTest, findOffersTest)
{
	m.initializeModel();
	m.findOffers(1);

	EXPECT_EQ(DEFAULT_NUMBER_OF_PRODUCERS, m.getOffers().size());
	EXPECT_TRUE(m.getOffers()[0].getPrice() < m.getOffers()[m.getOffers().size() / 2].getPrice());
	EXPECT_TRUE(m.getOffers()[m.getOffers().size() / 2].getPrice() < m.getOffers()[m.getOffers().size() - 1].getPrice());
}

TEST_F(SimulationManagerTest, increasePricesTest)
{
	m.initializeModel();
	double price = m.getProducer(1).getProductPrice(1);
	m.increasePrices();

	EXPECT_GT(m.getProducer(1).getProductPrice(1), price);
}

TEST_F(SimulationManagerTest, getBankruptProducer)
{
	m.initializeModel();

	EXPECT_EQ(-1, m.getBankruptProducer());

	m.chooseProductType();
	for(int i = 0; i < 400; i++)
		m.producersPayments();

	EXPECT_NE(-1,m.getBankruptProducer());
}

TEST_F(SimulationManagerTest, transferSlariesTest)
{
	m.initializeModel();
	double cash = m.getConsumersAverageCash();
	m.transferSalaries();

	EXPECT_EQ(m.getConsumersAverageCash(), cash + DEFAULT_CONSUMER_SALARY);
}

TEST_F(SimulationManagerTest, informCustomersTest)
{
	m.initializeModel();
	int i = m.chooseProductType();
	m.findOffers(i);
	int id = m.getOffers()[0].getProducerID();

	EXPECT_EQ(READY, m.getProducer(id).getFactory(0).getState());

	m.informConsumers(i);
	m.realizeOrders();

	EXPECT_EQ(RUNNING, m.getProducer(id).getFactory(0).getState());
}

TEST_F(SimulationManagerTest, isProducerInterestedTest)
{
	m.initializeModel();
	Order order(1, 1, 100, 1, 1);
	Order order2(1, 1, 1000, 100, 1);
	
	EXPECT_TRUE(m.isProducerInterested(order));
	EXPECT_FALSE(m.isProducerInterested(order2));
}

TEST_F(SimulationManagerTest, transactionTest)
{
	m.initializeModel();
	m.transaction(1, 1, 1000.0);

	EXPECT_EQ(DEFAULT_PRODUCER_CASH + 1000.0, m.getProducer(0).getCash());
	EXPECT_EQ(DEFAULT_CONSUMER_CASH - 1000.0 / DEFAULT_NUMBER_OF_CONSUMERS, m.getConsumersAverageCash());
}

TEST_F(SimulationManagerTest, cyclesTest)
{
	m.initializeModel();
	m.nextCycle();
	double price = m.getProducer(0).getProductPrice(1);
	
	EXPECT_EQ(2, m.getCycleNumber());

	for(int i = 0; i < 9; i++)
		m.nextCycle();

	EXPECT_GT(m.getProducer(0).getProductPrice(1), price);
}

TEST_F(SimulationManagerTest, randomGeneratorTest)
{
	EXPECT_GE(m.randomNumberGenerator(0.0, 10.0), 0.0);
	EXPECT_LE(m.randomNumberGenerator(0.0, 10.0), 10.0);
}



