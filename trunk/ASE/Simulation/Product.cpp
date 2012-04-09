///////////////////////////////////////////////////////////
//  Product.cpp
//  Implementation of the Class Product
//  Created on:      03-kwi-2012 23:55:01
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Product.h"
#include "Model.h"

int Product::idGenerator = 0;

Product::Product(int type, double price) : id(++idGenerator), cyclesToProduce(DEFAULT_PRODUCT_MANUFACTURING_LENGTH), manufactureCost(DEFAULT_PRODUCT_MANUFACTURING_COST), completnessFactor(0.0), type(type), price(price)
{

}

Product::~Product(){

}

void Product::increasePrice(double percentage)
{
	price *= (1.0 + percentage/100.0);
}

double Product::produce(double process)
{
	double tmp = cyclesToProduce;
	completnessFactor += process/tmp;
	if(completnessFactor > 1.0) completnessFactor = 1.0;

	return completnessFactor;
}

double Product::getCompletnessFactor()
{
	return completnessFactor;
}

int Product::getProductType()
{
	return type;
}

double Product::getPrice() const
{
	return price;
}

