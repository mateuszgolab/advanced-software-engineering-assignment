#include "gtest/gtest.h"
#include "Producer.h"

TEST(buildFactoryTest, positiveTest) 
{
	Producer producer;
	Factory factory = producer.buildFactory();
	EXPECT_EQ(FactoryState::INIT, factory.getState());

}

TEST(payFactoryStartUpTest, positiveTest)
{
	Producer p;
	p.payFactoryStartUp();
	EXPECT_EQ(9985, p.getCash());
}

TEST(realizeOrderTest, positiveTest)
{
	Order order(1, 1, 10, 1, 1);
	Producer p;
	EXPECT_TRUE(p.realizeOrder(order));
}

TEST(realizeOrderTest, negativeTest)
{
	Order order(1, 1, 100, 10000, 1);
	Producer p;
	EXPECT_FALSE(p.realizeOrder(order));
}

TEST(receiveCashTest, positiveTest)
{
	Producer p;
	p.receiveCash(1000);
	EXPECT_EQ(1150, p.getCash());
}

TEST(receiveCashTest, negativeTest)
{
	Producer p;
	p.receiveCash(-1000);
	EXPECT_EQ(150, p.getCash());
}





