///////////////////////////////////////////////////////////
//  ModelManager.h
//  Implementation of the Class ModelManager
//  Created on:      03-kwi-2012 23:55:07
//  Original author: Mateusz
///////////////////////////////////////////////////////////

#if !defined(EA_BAE4571B_5E5A_4be8_A340_237CBAD1BDDE__INCLUDED_)
#define EA_BAE4571B_5E5A_4be8_A340_237CBAD1BDDE__INCLUDED_

#include "Model.h"

class ModelManager
{

public:
	ModelManager(Model& m);
	virtual ~ModelManager();
	Model *m_Model;

	int getCheapestProducer(int productID);
	void initializeModel();
	void setParameters();

private:
	Model model;

};
#endif // !defined(EA_BAE4571B_5E5A_4be8_A340_237CBAD1BDDE__INCLUDED_)
