/*File Name: ShuttleControler.cpp
Programmer: Joesph Olliff
Purpose: Simulates the movements of a shuttle ferry moving passengers between two ports*/

#include <iostream>
#include "ShuttleBoat.h"
using namespace std;

int main()
{
	int destination = 0;
	int passHome = 0;
	int passDest = 0;

	cout << "Please enter the Destination port: ";
	cin >> destination;
	cout << "\n\nPlease enter the number of people at the Home Port: ";
	cin >> passHome;
	cout << "\n\nPlease enter the number of people at the Destination Port: ";
	cin >> passDest;

	ShuttleBoat cruiser("USS Shimmy", 1, destination, 125, passHome, passDest);
	int countHome = cruiser.getBoardingHome();
	int countDest = cruiser.getBoardingDest();

	while (countHome != 0 && countDest != 0)
	{
		cruiser.loadPassengers();
		cruiser.changePort();
		cruiser.offloadPassengers();
		countHome = cruiser.getBoardingHome();
		countDest = cruiser.getBoardingDest();
	}

	int temp = cruiser.getCurrentPort();
	if (temp != 1)
	{
		cruiser.changePort();
	}

	cout << "All passengers ferried to their destinations..." << endl;
	system("pause");
	return 0;
}