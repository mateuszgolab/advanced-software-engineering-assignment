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

#define  DEFAULT_CASH_OSCILATION 10
#define  DEFAULT_CONSUMER_CASH 150
#define  DEFAULT_CONSUMER_SALARY 100
#define  DEFAULT_FACTORY_CONSTRUCTION_COST 1500
#define  DEFAULT_FACTORY_RUNNING_COST 50
#define  DEFAULT_IDLE_FACTORY_STARTUP_COST 15
#define  DEFAULT_NUMBER_OF_CONSUMERS 1000
#define  DEFAULT_NUMBER_OF_PRODUCERS 15
#define  DEFAULT_PRODUCER_CASH 10000
#define  DEFAULT_PRODUCT_MANUFACTURING_COST 5
#define  DEFAULT_PRODUCT_MANUFACTURING_LENGTH 5
#define  DEFAULT_QUEUE_THRESHOLD 100


class Model
{

public:
	Model();
	virtual ~Model();

	void setConsumerCash(double cash, double var);
	void setFactoryConstructionCost(double cost);
	void setFactoryRunningCost(double cost);
	void setIdleFactoryStartUpCost(double cost);
	void setNumberOfConsumers(int numberOfConsumers);
	void setNumberOfProducers(int numberOfProducers);
	void setProducerCash(double cash, double var);
	void setProductManufacturingCost(std::vector<double> costs);
	void setProductManufacturingTime(std::vector<int> cycles);
	void setQueueOrdersThreshold(int threshold);
	int getNumberOfProducers() const;
	int getNumberOfConsumers() const;
	double getCashPerProducer() const;
	double getCashPerConsumer() const;
	double getConsumerSalary() const;
	double getFactoryRunningCost() const;
	double getFactoryConstructionCost() const;
	double getIdleFactoryStartupCost() const;
	int getQueueOrdersThreshold() const;

private:
	double cashPerConsumer;
	double cashPerProducer;
	double consumerCashOscilation;
	double consumerSalary;
	double factoryConstructionCost;
	double factoryRunningCost;
	double idleFactoryStartUpCost;
	int numberOfConsumers;
	int numberOfProducers;
	double producerCashOscilation;
	int queueOrdersThreshold;

};
#endif // !defined(EA_99D29BE5_0334_4416_82A3_3571A7F7D8FB__INCLUDED_)
