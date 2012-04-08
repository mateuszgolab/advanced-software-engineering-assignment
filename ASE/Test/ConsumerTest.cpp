#include "gtest/gtest.h"
#include "Consumer.h"
#include "Producer.h"
#include "SimulationManager.h"

class ConsumerTest : public ::testing::Test
{
protected :
	Consumer c;
	SimulationManager sm;

	ConsumerTest() : c(150, 100), sm()
	{
		sm.initializeModel();
		sm.findOffers(1);
	}
};

TEST_F(ConsumerTest, makeOrderTest)
{
	c.makeOrder(1);
	EXPECT_EQ(PRODUCT_ORDERED, c.getState());
}

TEST_F(ConsumerTest, payProducerTest)
{
	c.payProducer(50);
	EXPECT_EQ(100, c.getCash());
}

TEST_F(ConsumerTest, receiveSalaryTest)
{
	c.receiveSalary();
	EXPECT_EQ(250, c.getCash());
}

TEST_F(ConsumerTest, setSalaryTest)
{
	Consumer c(100, 50);
	c.setSalary(200);
	c.receiveSalary();
	EXPECT_EQ(300, c.getCash());
}

TEST_F(ConsumerTest, getCashTest)
{
	Consumer c(100, 50);
	EXPECT_EQ(100, c.getCash());
}

TEST_F(ConsumerTest, getStateTest)
{
	Consumer c(100, 50);
	EXPECT_EQ(NOTHING_ORDERED, c.getState());
}

