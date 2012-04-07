///////////////////////////////////////////////////////////
//  Order.cpp
//  Implementation of the Class Order
//  Created on:      03-kwi-2012 23:55:03
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Order.h"
#include "SimulationManager.h"

using namespace std;

Order::Order() : consumerID(0), producerID(0), cost(0), productType(0)
{

}

Order::Order(int cID, int pID, double c, int n, int pType) : consumerID(cID), producerID(pID), cost(c), productType(pType)
{
	products.reserve(n);
	for(int i = 0; i < n; i++)
		products[i] = SimulationManager::createProduct(pType);
}

Order::~Order(){

}

int Order::getNumberOfProducts()
{
	return products.size();
}

Product Order::getProduct(int i)
{
	return products[i];
}

int Order::getID()
{
	return id;
}

int Order::getProducerID()
{
	return producerID;
}

vector<Product>::iterator Order::getProductIterator()
{
	return products.begin();
}