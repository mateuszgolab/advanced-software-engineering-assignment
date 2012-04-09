#include "gtest/gtest.h"
#include "Factory.h"
#include "SimulationManager.h"

class FactoryTest : public ::testing::Test
{
protected :
	Factory f;
	SimulationManager sm;
	Product p;

	FactoryTest() : f(1.0), sm(), p(1, 5.0)
	{
		sm.initializeModel();
		sm.findOffers(1);
	}
};


TEST_F(FactoryTest, manufactureTest) 
{
	EXPECT_LE(f.manufacture(&p), 1.0);

}

TEST_F(FactoryTest, manufactureTest2) 
{
	f.manufacture(&p);
	EXPECT_LE(f.manufacture(), 1.0);
	EXPECT_LE(f.manufacture(), 1.0);
	EXPECT_LE(f.manufacture(), 1.0);
	EXPECT_EQ(f.manufacture(), 1.0);

}

TEST_F(FactoryTest, incIdleTimeTest) 
{
	f.setState(IDLE);
	EXPECT_EQ(0, f.getIdleTime());
	f.incIdleTime();
	EXPECT_EQ(1, f.getIdleTime());
}










