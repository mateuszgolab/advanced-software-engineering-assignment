#include "gtest/gtest.h"
#include "Product.h"

class ProductTest : public ::testing::Test
{
protected:
	Product p;

	ProductTest() : p(1, 10.0)
	{
	}
};


TEST_F(ProductTest, increasePricesTest)
{
	p.increasePrice(5.0);
	EXPECT_EQ(10.5, p.getPrice());
}

TEST_F(ProductTest, produceTest)
{
	p.produce(2.0);
	EXPECT_EQ(0.4, p.getCompletnessFactor());
}

TEST_F(ProductTest, getTypeTest)
{
	EXPECT_EQ(1, p.getProductType());
}