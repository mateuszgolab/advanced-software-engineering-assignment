///////////////////////////////////////////////////////////
//  Offer.cpp
//  Implementation of the Class Offer
//  Created on:      07-kwi-2012 00:10:40
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Offer.h"


Offer::Offer(int producerID, double price) : producerID(producerID), price(price)
{

}



Offer::~Offer(){

}

int Offer::getProducerID()
{
	return producerID;
}

double Offer::getPrice()
{
	return price;
}

void Offer::setPrice(double price)
{
	this->price = price;
}

void Offer::setProducerID(int id)
{
	this->producerID = id;
}