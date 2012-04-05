///////////////////////////////////////////////////////////
//  Order.cpp
//  Implementation of the Class Order
//  Created on:      03-kwi-2012 23:55:03
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Order.h"


Order::Order() : consumerID(0), producerID(0), cost(0), numberOfProducts(0), productID(0)
{

}

Order::Order(int cID, int pID, double c, int n, int pType) : consumerID(cID), producerID(pID), cost(c), numberOfProducts(n), productType(pType)
{
}

Order::~Order(){

}

int Order::getNumberOfProducts()
{
	return numberOfProducts;
}


