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

	bool buildFactory();
	void demolishUnusedFactories();
	void realizeOrders();
	void receiveCash(double cash);
	double getCash();
	double getProductPrice(int productType);
	int getID();
	bool acceptOrder(Order & order);
	int getNumberOfOrders();
	int getNumberOfCompletedOrders();
	int getNumberOfFactories();
	Factory& getFactory(int index);
	void payForFactories();
	bool payForProduct(int productType);
	bool payFactoryStartUp();
	void finalizeOrders();
	void increasePrices(double percentage);

private:
	int id;
	double cash;
	double productsPrices[5];
	std::vector<Factory> factories;
	std::vector<Order> orders;
	int numberOfProducts;
	int numberOfCompletedOrders;
	std::vector<Order>::iterator ordersIterator;
	std::vector<Product>::iterator productIterator;
	bool iteratorsInitialized;

	static int idGenerator;
	static int threshold;

};
#endif // !defined(EA_D0034D42_1E14_4255_A24E_CEADEB63F899__INCLUDED_)
