///////////////////////////////////////////////////////////
//  Offer.cpp
//  Implementation of the Class Offer
//  Created on:      07-04-2012 00:10:40
//  Original author: Mateusz Golab
///////////////////////////////////////////////////////////

#include "Offer.h"


Offer::Offer() : producerID(0), price(0.0)
{
}

Offer::Offer(int producerID, double price) : producerID(producerID), price(price)
{

}



Offer::~Offer(){

}

bool Offer::operator()(const Offer & o1, const Offer & o2)
{
	return o1.getPrice() < o2.getPrice();
}

int Offer::getProducerID()
{
	return producerID;
}

double Offer::getPrice() const
{
	return price;
}

