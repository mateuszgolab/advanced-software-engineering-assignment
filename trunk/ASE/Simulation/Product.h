///////////////////////////////////////////////////////////
//  Product.h
//  Implementation of the Class Product
//  Created on:      03-kwi-2012 23:55:01
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_D0AEA351_AEA0_4b1c_84C2_1C8A3FAC4AA1__INCLUDED_)
#define EA_D0AEA351_AEA0_4b1c_84C2_1C8A3FAC4AA1__INCLUDED_


class Product
{

public:
	Product();
	virtual ~Product();

	double getProportion();
	void increasePrice(double percentage);
	void setPrice(double price);
	void produce(double process);

private:
	int id;
	int cyclesToProduce;
	double price;
	double manufactureCost;
	double levelOfCompletness;

};
#endif // !defined(EA_D0AEA351_AEA0_4b1c_84C2_1C8A3FAC4AA1__INCLUDED_)
