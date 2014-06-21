/*File Name: FerryController.cpp
Programmer: Joesph Olliff
Purpose: Controller Program to simulate the movements of a ferryboat as it ferrys passengers*/

#include <iostream>
#include "FerryBoat.h"

using namespace std;

int main()
{
	FerryBoat cruiser(20, 120, 1, "USS Reliant"); //Instantiate the USS Reliant

	cruiser.loadPassengers();//Load initial passengers from Home port

	//Simulate a series of runs
	cruiser.changePort(18);
	cruiser.changePort(15);
	cruiser.changePort(20);
	cruiser.changePort(4);
	cruiser.changePort(35);

	system("pause");
	return 0;
}