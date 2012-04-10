///////////////////////////////////////////////////////////
//  Offer.h
//  Implementation of the Class Offer
//  Created on:      07-04-2012 00:10:40
//  Original author: Mateusz Golab
///////////////////////////////////////////////////////////

#if !defined(EA_B665EB1D_C82A_44f6_9069_5225D96B5ED4__INCLUDED_)
#define EA_B665EB1D_C82A_44f6_9069_5225D96B5ED4__INCLUDED_

class Offer
{

public:
	Offer();
	Offer(int producerID, double price);
	virtual ~Offer();
	
	int getProducerID();
	double getPrice() const;
	bool operator()(const Offer & o1, const Offer & o2);

private:
	double price;
	int producerID;

};
#endif // !defined(EA_B665EB1D_C82A_44f6_9069_5225D96B5ED4__INCLUDED_)
