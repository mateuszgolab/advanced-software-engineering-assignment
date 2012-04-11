///////////////////////////////////////////////////////////
//  Consumer.h
//  Implementation of the Class Consumer
//  Created on:      03-04-2012 23:54:57
//  Original author: Mateusz Golab
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

	void makeOrder(int productType);
	void payProducer(double price);
	void receiveSalary();
	void setSalary(double salary);
	double getCash();
	ConsumerState getState();
	int getID();
	

private:
	double cash;
	double salary;
	int id;
	ConsumerState state;
	static int idGenerator;

};
#endif // !defined(EA_4C8BA131_6174_46eb_84BC_52EFDD82A7BD__INCLUDED_)
