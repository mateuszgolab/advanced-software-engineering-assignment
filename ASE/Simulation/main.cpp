#include<iostream>
#include"ModelManager.h"
#include"SimulationManager.h"


using namespace std;

int main(int argc, char *argv[])
{
	Model model;
	ModelManager modelManager(model);
	modelManager.setParameters();
	modelManager.initializeModel();

	SimulationManager simulationManager(model);
	simulationManager.startSimulation();

	return 0;
}