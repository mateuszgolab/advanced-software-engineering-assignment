///////////////////////////////////////////////////////////
//  Producer.h
//  Implementation of the Class Producer
//  Created on:      03-kwi-2012 23:54:54
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_D0034D42_1E14_4255_A24E_CEADEB63F899__INCLUDED_)
#define EA_D0034D42_1E14_4255_A24E_CEADEB63F899__INCLUDED_

#include "Factory.h"
#include "Order.h"
#include <stdlib.h>
#include <time.h>

class Producer
{

public:
	Producer(double cash);
	virtual ~Producer();

	Factory buildFactory();
	void payFactoryStartUp();
	void realizeOrders();
	void receiveCash(double cash);
	double getCash();
	double getProductPrice(int productType);
	int getID();
	bool acceptOrder(Order & order);
	int getNumberOfOrders();
	int getNumberOfCompletedOrders();
	int getNumberOfFactories();
	Factory getFactory(int index);
	void payForFactories();

private:
	int id;
	double cash;
	double productsPrices[5];
	std::vector<Factory> factories;
	std::vector<Order> orders;
	int numberOfProducts;
	int numberOfCompletedOrders;

	static int idGenerator;
	static int threshold;

};
#endif // !defined(EA_D0034D42_1E14_4255_A24E_CEADEB63F899__INCLUDED_)