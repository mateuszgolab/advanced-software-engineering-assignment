///////////////////////////////////////////////////////////
//  SimulationManager.h
//  Implementation of the Class SimulationManager
//  Created on:      03-kwi-2012 23:54:59
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_C8DA3665_B677_453f_B292_9AA5F37D2A53__INCLUDED_)
#define EA_C8DA3665_B677_453f_B292_9AA5F37D2A53__INCLUDED_

#include "Model.h"
#include "Offer.h"


class SimulationManager
{

public:
	SimulationManager(Model& model);
	SimulationManager();
	virtual ~SimulationManager();

	void demolishUnusedFactories();
	void increasePrices();
	int getBankruptProducer();
	void initializeModel();
	void transferSalaries();
	int chooseProductType();
	void informConsumers(int productType);
	void findOffers(int productType);
	void nextCycle();
	double getConsumersAverageCash();
	int getNumberOfConsumers();
	int getNumberOfProducers();
	void realizeOrders();
	void producersPayments();

	static Producer& getProducer(int id);
	static std::vector<Offer> getOffers();
	static double randomNumberGenerator(double low, double high);
	static bool isProducerInterested(Order order);
	static void transaction(int producerID, int consumerID, double cash);
	static int getCycleNumber();

private:
	Model model;
	int currentProductType;
	static int cycle;
	static std::vector<Offer> offers;
	static std::vector<Producer> producers;
	static std::vector<Consumer> consumers;

};
#endif // !defined(EA_C8DA3665_B677_453f_B292_9AA5F37D2A53__INCLUDED_)
