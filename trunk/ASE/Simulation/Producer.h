///////////////////////////////////////////////////////////
//  Producer.h
//  Implementation of the Class Producer
//  Created on:      03-04-2012 23:54:54
//  Original author: Mateusz Golab
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
	Producer(double cash, int threshold, std::vector<double> costs, std::vector<double> lengths);
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
	void payForFactories();
	bool payForProduct(int productType);
	bool payFactoryStartUp();
	void finalizeOrders();
	void increasePrices(double percentage);
	Product & getProduct();
	Factory& getFactory(int index);
	

private:
	int id;
	double cash;
	double productsPrices[5];
	double productsCosts[5];
	double productsLengths[5];
	std::vector<Factory> factories;
	std::vector<Order> orders;
	int numberOfProducts;
	int numberOfCompletedOrders;
	int ordersIterator;
	int productIterator;
	int threshold;

	static int idGenerator;

};
#endif // !defined(EA_D0034D42_1E14_4255_A24E_CEADEB63F899__INCLUDED_)
