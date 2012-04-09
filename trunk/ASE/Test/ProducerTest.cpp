#include "gtest/gtest.h"
#include "Producer.h"
#include "SimulationManager.h"

class ProducerTest : public ::testing::Test
{
protected :
	Producer p;
	SimulationManager sm;

	ProducerTest() : p(DEFAULT_PRODUCER_CASH), sm()
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
	EXPECT_EQ(19985, p.getCash());
}

TEST_F(ProducerTest, realizeOrderTest1)
{
	p.buildFactory();
	p.getFactory(1).setState(IDLE);

	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.acceptOrder(Order(1,1, 100, 1, 1));
	for(int i = 0; i < 10; i++) p.realizeOrders();

	EXPECT_EQ(IDLE, p.getFactory(0).getState());
	EXPECT_EQ(IDLE, p.getFactory(1).getState());
	EXPECT_EQ(2, p.getNumberOfOrders());
}

TEST_F(ProducerTest, realizeOrderTest2)
{
	p.buildFactory();
	p.getFactory(1).setState(IDLE);

	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.realizeOrders();
	p.acceptOrder(Order(1,1, 100, 1, 1));

	EXPECT_EQ(RUNNING, p.getFactory(0).getState());
	EXPECT_EQ(RUNNING, p.getFactory(1).getState());
	EXPECT_EQ(3, p.getNumberOfOrders());
}

TEST_F(ProducerTest, realizeOrderTest3)
{
	p.buildFactory();
	p.getFactory(1).setState(IDLE);

	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.realizeOrders();


	EXPECT_EQ(RUNNING, p.getFactory(0).getState());
	EXPECT_EQ(RUNNING, p.getFactory(1).getState());
	EXPECT_EQ(RUNNING, p.getFactory(2).getState());
	EXPECT_EQ(3, p.getNumberOfOrders());

}

TEST_F(ProducerTest, receiveCashTest)
{
	p.receiveCash(1000);
	EXPECT_EQ(21000, p.getCash());
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
	EXPECT_GE(p.getProductPrice(1), 2 * DEFAULT_PRODUCT_MANUFACTURING_COST);
	EXPECT_LE(p.getProductPrice(1), 10 * DEFAULT_PRODUCT_MANUFACTURING_COST);
}

TEST_F(ProducerTest, payForFactoriesTest)
{
	p.payForFactories();
	EXPECT_EQ(19950, p.getCash());
}

TEST_F(ProducerTest, payForProductTest)
{
	p.payForProduct(1);
	EXPECT_GE(p.getCash(), DEFAULT_PRODUCER_CASH - 10 * DEFAULT_PRODUCT_MANUFACTURING_COST);
	EXPECT_LE(p.getCash(), DEFAULT_PRODUCER_CASH - 2 * DEFAULT_PRODUCT_MANUFACTURING_COST);
}

TEST_F(ProducerTest, finalizeOrdersTest)
{
	p.finalizeOrders();
	EXPECT_EQ(0, p.getNumberOfCompletedOrders());
}

TEST_F(ProducerTest, finalizeOrdersTest2)
{
	p.buildFactory();
	p.getFactory(1).setState(IDLE);
	p.acceptOrder(Order(1,1, 100, 1, 1));
	p.acceptOrder(Order(1,1, 100, 1, 1));
	for(int i = 0; i < 10; i++) p.realizeOrders();
	p.finalizeOrders();
	EXPECT_EQ(2, p.getNumberOfCompletedOrders());
	EXPECT_EQ(0, p.getNumberOfOrders());
}

TEST_F(ProducerTest, increasePricesTest)
{
	p.increasePrices(100.0);

	EXPECT_GE(p.getProductPrice(1), 4 * DEFAULT_PRODUCT_MANUFACTURING_COST);
	EXPECT_LE(p.getProductPrice(1), 20 * DEFAULT_PRODUCT_MANUFACTURING_COST);
}

TEST_F(ProducerTest, acceptOrderTest)
{
	p.acceptOrder(Order(1,1, 100, 50, 1));
	EXPECT_FALSE(p.acceptOrder(Order(1,1, 100, 1, 1)));
	EXPECT_EQ(1, p.getNumberOfOrders());
}




	








