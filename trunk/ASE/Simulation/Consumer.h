///////////////////////////////////////////////////////////
//  Consumer.h
//  Implementation of the Class Consumer
//  Created on:      03-kwi-2012 23:54:57
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_4C8BA131_6174_46eb_84BC_52EFDD82A7BD__INCLUDED_)
#define EA_4C8BA131_6174_46eb_84BC_52EFDD82A7BD__INCLUDED_

#include"Order.h"
#include"ConsumerState.h"

class Consumer
{

public:
	Consumer(double cash, double salary);
	virtual ~Consumer();

	Order makeOrder(int productID);
	void payProducer(double price, int producerID);
	void receiveSalary();
	void setSalary(double salary);
	double getCash();
	ConsumerState getState();
	

private:
	double cash;
	double salary;
	double id;
	ConsumerState state;
	
	static int idGenerator;

};
#endif // !defined(EA_4C8BA131_6174_46eb_84BC_52EFDD82A7BD__INCLUDED_)
