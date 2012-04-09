#include "gtest/gtest.h"
#include "Order.h"
#include "Product.h"
#include "Producer.h"
#include "SimulationManager.h"

class OrderTest : public ::testing::Test
{
protected :
	Order o;
	Product p;

	OrderTest() : o(1, 1, 10, 10, 1), p(o.getProduct(0))
	{
		
	}
};

TEST_F(OrderTest, getProductTest)
{
	EXPECT_EQ(1, p.getProductType());
}

TEST_F(OrderTest, getConsumerIDTest)
{
	EXPECT_EQ(1, o.getConsumerID());
}

TEST_F(OrderTest, getProducerIDTest)
{
	EXPECT_EQ(1, o.getProducerID());
}

TEST_F(OrderTest, getNumberOfProductsTest)
{
	EXPECT_EQ(10, o.getNumberOfProducts());
}

TEST_F(OrderTest, getCostTest)
{
	EXPECT_EQ(10.0, o.getCost());
}

TEST_F(OrderTest, isCompletedTest1)
{
	EXPECT_FALSE(o.isCompleted());
}

TEST_F(OrderTest, isCompletedTest2)
{
	SimulationManager m;
	m.initializeModel();


	Producer pr(90000);
	pr.acceptOrder(o);
	
	for(int i = 0; i < 100; i++)
		pr.realizeOrders();

	pr.finalizeOrders();

	EXPECT_EQ(1, pr.getNumberOfCompletedOrders());
}

TEST_F(OrderTest, getIDTest)
{
	EXPECT_GE(o.getID(), 1);
}

