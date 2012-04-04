///////////////////////////////////////////////////////////
//  Producer.cpp
//  Implementation of the Class Producer
//  Created on:      03-kwi-2012 23:54:54
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Producer.h"


using namespace std;

Producer::Producer(){

}



Producer::~Producer(){

}





Factory Producer::buildFactory(){
	return Factory();
}


void Producer::payFactoryStartUp(){

}


bool Producer::realizeOrder(Order order){

	return  NULL;
}


void Producer::receiveCash(double cash){

}


void Producer::sellProducts(vector<Product> products){

}