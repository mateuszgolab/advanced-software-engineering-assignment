#include "gtest/gtest.h"
#include "Consumer.h"

TEST(makeOrderTest, positiveTest)
{
	/*Consumer c(1, 1000, 50);
	Order order = c.makeOrder(1, 100);
	EXPECT_EQ(10, order.getNumberOfProducts());*/

}

TEST(payProducerTest, positiveTest)
{
	Consumer c(1, 1000, 50);
	c.payProducer(500, 1);
	EXPECT_EQ(500, c.getCash());

}

TEST(receiveSalaryTest, posotiveTest)
{
	Consumer c(1, 100, 50);
	c.receiveSalary();
	EXPECT_EQ(150, c.getCash());
}