#include "gtest/gtest.h"
#include "Factory.h"

TEST(manufactureProductTest, positiveTest)
{
	Factory f;
	Product p = f.manufactureProduct();
	