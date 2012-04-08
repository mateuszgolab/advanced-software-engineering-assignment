///////////////////////////////////////////////////////////
//  Product.cpp
//  Implementation of the Class Product
//  Created on:      03-kwi-2012 23:55:01
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Product.h"
#include "Model.h"

int Product::idGenerator = 0;

Product::Product(int type) : id(++idGenerator), cyclesToProduce(DEFAULT_PRODUCT_MANUFACTURING_LENGTH), manufactureCost(DEFAULT_PRODUCT_MANUFACTURING_COST), completnessFactor(0.0), type(type)
{

}

Product::~Product(){

}

double Product::getProportion(){

	return 0;
}

void Product::increasePrice(double percentage){

}

void Product::setPrice(double price)
{
	this->price = price;
}

double Product::produce(double process)
{
	completnessFactor += process;
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
