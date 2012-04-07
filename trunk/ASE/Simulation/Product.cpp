///////////////////////////////////////////////////////////
//  Product.cpp
//  Implementation of the Class Product
//  Created on:      03-kwi-2012 23:55:01
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Product.h"


Product::Product(){

}

Product::~Product(){

}

double Product::getProportion(){

	return 0;
}

void Product::increasePrice(double percentage){

}

void Product::setPrice(double price){

}

void Product::produce(double process)
{
	levelOfCompletness += process;
	if(levelOfCompletness > 1.0) levelOfCompletness = 1.0;

}