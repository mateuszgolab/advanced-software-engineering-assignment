///////////////////////////////////////////////////////////
//  Order.cpp
//  Implementation of the Class Order
//  Created on:      03-kwi-2012 23:55:03
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Order.h"


using namespace std;

int Order::idGenerator = 0;

Order::Order() : consumerID(0), producerID(0), cost(0), productType(0), id(++idGenerator)
{

}

Order::Order(int cID, int pID, double c, int n, int pType) : consumerID(cID), producerID(pID), cost(c), productType(pType), id(++idGenerator)
{
	products.reserve(n);
	for(int i = 0; i < n; i++)
		products.push_back(Product(pType, cost / n));
}

Order::~Order(){

}

int Order::getNumberOfProducts()
{
	return products.size();
}

Product& Order::getProduct(int i)
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

vector<Product>::iterator Order::getBeginIterator()
{
	return products.begin();
}

vector<Product>::iterator Order::getEndIterator()
{
	return products.end();
}

int Order::getProductType()
{
	return productType;
}

bool Order::isCompleted()
{
	for(vector<Product>::iterator it = products.begin(); it != products.end(); it++)
	{
		if((*it).getCompletnessFactor() < 1.0) return false;
	}

	return true;
}

int Order::getConsumerID()
{
	return consumerID;
}

double Order::getCost()
{
	return cost;
}