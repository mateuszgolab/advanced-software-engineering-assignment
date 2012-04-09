#include "gtest/gtest.h"
#include "Offer.h"

class OfferTest : public ::testing::Test
{
protected :
	Offer o, o1;
	
	OfferTest() : o(1, 10.0), o1(2, 6.0)
	{
		
	}
};

TEST_F(OfferTest, compareOperatorTest)
{
	EXPECT_TRUE(o1(o1, o));
}

TEST_F(OfferTest, getPriceTest)
{
	EXPECT_EQ(10.0, o.getPrice());
}

TEST_F(OfferTest, getProducerIDTest)
{
	EXPECT_EQ(1, o.getProducerID());
}

