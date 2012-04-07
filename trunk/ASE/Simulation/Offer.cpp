///////////////////////////////////////////////////////////
//  Offer.cpp
//  Implementation of the Class Offer
//  Created on:      07-kwi-2012 00:10:40
//  Original author: Mateusz
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

void Offer::setPrice(double price)
{
	this->price = price;
}

void Offer::setProducerID(int id)
{
	this->producerID = id;
}