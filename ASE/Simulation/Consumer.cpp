///////////////////////////////////////////////////////////
//  Consumer.cpp
//  Implementation of the Class Consumer
//  Created on:      03-kwi-2012 23:54:57
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Consumer.h"


Consumer::Consumer(int id, double cash, double salary) : id(id), cash(cash), salary(salary) 
{

}



Consumer::~Consumer(){

}





Order Consumer::makeOrder(int productID, double cost)
{
	
}


void Consumer::payProducer(double price, int producerID){

}


void Consumer::receiveSalary(){

}


void Consumer::setSalary(double salary){

}

void Consumer::checkNewProduct(int productID)
{

}

double Consumer::getCash()
{
	return cash;
}

