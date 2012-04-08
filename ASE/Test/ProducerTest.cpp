#include "gtest/gtest.h"
#include "Producer.h"
#include "SimulationManager.h"

class ProducerTest : public ::testing::Test
{
protected :
	Producer p;
	SimulationManager sm;

	ProducerTest() : p(10000), sm()
	{
		sm.initializeModel();
		sm.findOffers(1);
	}
};


TEST_F(ProducerTest, buildFactoryTest) 
{
	p.buildFactory();
	EXPECT_EQ(2, p.getNumberOfFactories());

}

TEST_F(ProducerTest, payFactoryStartUpTest)
{
	p.payFactoryStartUp();
	EXPECT_EQ(9985, p.getCash());
}

TEST_F(ProducerTest, realizeOrderTest)
{
	p.buildFactory();
	p.getFactory(1).setState(IDLE);

	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.acceptOrder(Order(1,1, 100, 1, 1));
	for(int i = 0; i < 5; i++) p.realizeOrders();

	EXPECT_EQ(READY, p.getFactory(0).getState());
	EXPECT_EQ(READY, p.getFactory(1).getState());
}

TEST_F(ProducerTest, realizeOrderTest2)
{
	//Order order(1, 1, 100, 10000, 1);
	//Producer p;
	//EXPECT_FALSE(p.realizeOrder(order));
}

TEST_F(ProducerTest, receiveCashTest)
{
	p.receiveCash(1000);
	EXPECT_EQ(11000, p.getCash());
}

TEST_F(ProducerTest, demolishUnusedFactoriesTest)
{
	for(int i = 0; i < 51; i++)
		p.getFactory(0).incIdleTime();
	p.demolishUnusedFactories();

	EXPECT_EQ(0, p.getNumberOfFactories());
}

TEST_F(ProducerTest, getProductPriceTest)
{
	EXPECT_GE(p.getProductPrice(1), 6.0);
	EXPECT_LE(p.getProductPrice(1), 10.0);
}

TEST_F(ProducerTest, payForFactoriesTest)
{
	p.payForFactories();
	EXPECT_EQ(9950, p.getCash());
}

TEST_F(ProducerTest, payForProductTest)
{
	p.payForProduct(1);
	EXPECT_GE(p.getCash(), 9990);
	EXPECT_LE(p.getCash(), 9995);
}

TEST_F(ProducerTest, finalizeOrdersTest)
{
	p.finalizeOrders();
	EXPECT_EQ(0, p.getNumberOfCompletedOrders());
}

TEST_F(ProducerTest, increasePricesTest)
{
	p.increasePrices(100.0);

	EXPECT_GE(p.getProductPrice(1), 12.0);
	EXPECT_LE(p.getProductPrice(1), 20.0);
}





	

	//int getNumberOfOrders();







