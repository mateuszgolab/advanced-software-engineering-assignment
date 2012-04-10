///////////////////////////////////////////////////////////
//  Order.h
//  Implementation of the Class Order
//  Created on:      03-04-2012 23:55:03
//  Original author: Mateusz Golab
///////////////////////////////////////////////////////////

#if !defined(EA_F4525D7B_9509_4d44_9828_F56249EB31DD__INCLUDED_)
#define EA_F4525D7B_9509_4d44_9828_F56249EB31DD__INCLUDED_

#include "Product.h"
#include <vector>

class Order
{

public:
	Order();
	Order(int consumerID, int producerID, double cost, int numberOfProducts, int productType);
	virtual ~Order();

	int getNumberOfProducts();
	Product& getProduct(int i);
	int getID();
	int getProducerID();
	int getConsumerID();
	double getCost();
	int getProductType();
	bool isCompleted();

private:
	int id;	
	int consumerID;
	int producerID;
	double cost;
	int productType;
	std::vector<Product> products;

	static int idGenerator;

};
#endif // !defined(EA_F4525D7B_9509_4d44_9828_F56249EB31DD__INCLUDED_)
