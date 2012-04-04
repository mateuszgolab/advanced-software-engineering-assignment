///////////////////////////////////////////////////////////
//  Model.h
//  Implementation of the Class Model
//  Created on:      03-kwi-2012 23:55:05
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_99D29BE5_0334_4416_82A3_3571A7F7D8FB__INCLUDED_)
#define EA_99D29BE5_0334_4416_82A3_3571A7F7D8FB__INCLUDED_

#include<iostream>
#include<vector>
#include"Consumer.h"
#include"Producer.h"
#include"Product.h"

#define  DEFAULT_CASH_OSCILATION
#define  DEFAULT_CUSTOMER_CASH
#define  DEFAULT_CUSTOMER_SALARY
#define  DEFAULT_FACTORY_CONSTRUCTION_COST
#define  DEFAULT_FACTORY_RUNNING_COST
#define  DEFAULT_IDLE_FACTORY_STARTUP_COST
#define  DEFAULT_NUMBER_OF_CUSTOMERS
#define  DEFAULT_NUMBER_OF_PRODUCERS
#define  DEFAULT_PRODUCER_CASH
#define  DEFAULT_PRODUCT_MANUFACTURING_COST
#define  DEFAULT_PRODUCT_MANUFACTURING_LENGTH


class Model
{

public:
	Model();
	virtual ~Model();

	void setCustomerCash(double cash, double var);
	void setFactoryConstructionCost(double cost);
	void setFactoryRunningCost(double cost);
	void setIdleFactoryStartUpCost(double cost);
	void setNumberOfCustomers(int numberOfCustomers);
	void setNumberOfProducers(int numberOfProducers);
	void setProducerCash(double cash, double var);
	void setProductManufacturingCost(std::vector<double> costs);
	void setProductManufacturingTime(std::vector<int> cycles);
	void setQueueOrdersThreshold(int threshold);

private:
	double cashOfCustomer;
	double cashPerProducer;
	double consumerCashOscilation;
	std::vector<Consumer> consumers;
	double customerSalary;
	double factoryConstructionCost;
	double factoryRunningCost;
	double idleFactoryStartUpCost;
	int numberOfCustomers;
	int numberOfProducers;
	double producerCashOscilation;
	std::vector<Producer> producers;
	std::vector<Product> products;
	int queueOrdersThreshold;

};
#endif // !defined(EA_99D29BE5_0334_4416_82A3_3571A7F7D8FB__INCLUDED_)
