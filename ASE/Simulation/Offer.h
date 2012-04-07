///////////////////////////////////////////////////////////
//  Offer.h
//  Implementation of the Class Offer
//  Created on:      07-kwi-2012 00:10:40
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_B665EB1D_C82A_44f6_9069_5225D96B5ED4__INCLUDED_)
#define EA_B665EB1D_C82A_44f6_9069_5225D96B5ED4__INCLUDED_

class Offer
{

public:
	Offer(int producerID, double price);
	virtual ~Offer();
	int getProducerID();
	void setProducerID(int id);
	double getPrice();
	void setPrice(double price);

private:
	double price;
	int producerID;

};
#endif // !defined(EA_B665EB1D_C82A_44f6_9069_5225D96B5ED4__INCLUDED_)
