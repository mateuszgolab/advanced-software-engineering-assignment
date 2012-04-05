///////////////////////////////////////////////////////////
//  Factory.cpp
//  Implementation of the Class Factory
//  Created on:      04-kwi-2012 12:40:28
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#include "Factory.h"


Factory::Factory(){

}



Factory::~Factory(){

}





int Factory::getIdleTime(){

	return 0;
}


Product Factory::manufactureProduct(){

	return  Product();
}

FactoryState Factory::getState()
{
	return FactoryState::IDLE;
}