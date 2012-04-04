///////////////////////////////////////////////////////////
//  Order.h
//  Implementation of the Class Order
//  Created on:      03-kwi-2012 23:55:03
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_F4525D7B_9509_4d44_9828_F56249EB31DD__INCLUDED_)
#define EA_F4525D7B_9509_4d44_9828_F56249EB31DD__INCLUDED_

#include "Product.h"
#include <vector>

class Order
{

public:
	Order();
	virtual ~Order();

private:
	int consumerID;
	double cost;
	int producerID;
	std::vector<Product> products;

};
#endif // !defined(EA_F4525D7B_9509_4d44_9828_F56249EB31DD__INCLUDED_)
