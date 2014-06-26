/*File Name: ShuttleBoat.cpp
Programmer: Joesph Olliff
Purpose: Method set for the ShuttleBoat*/

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "ShuttleBoat.h"
using namespace std;

ShuttleBoat::ShuttleBoat(string shipName, int homePort, int targetPort, int maxCap, int homePass, int destPass)
{
	boatID = shipName;
	currentPort = homePort;
	destPort = targetPort;
	passengers = 0;
	capacity = maxCap;
	boardingHome = homePass;
	boardingDest = destPass;
	srand(time(NULL)); //seed random number gen
}

int ShuttleBoat::getBoardingDest()
{
	return boardingDest;
}

int ShuttleBoat::getBoardingHome()
{
	return boardingHome;
}

string ShuttleBoat::getBoatID()
{
	return boatID;
}

int ShuttleBoat::getCapacity()
{
	return capacity;
}

int ShuttleBoat::getCurrentPort()
{
	return currentPort;
}

int ShuttleBoat::getDestPort()
{
	return destPort;
}

int ShuttleBoat::getPassengers()
{
	return passengers;
}

void ShuttleBoat::loadPassengers()
{
	int missed = 0;
	if (currentPort == 1)
	{
		missed = missChance();
		if (boardingHome > capacity)
		{
			passengers = capacity - missed;
			boardingHome -= capacity + missed;
			cout << passengers << " passengers loaded at port " << currentPort << endl;
			cout << boardingHome << " passengers remain at port " << currentPort << endl;
			cout << missed << " Passengers missed their trip!" << endl;
		}
		else
		{
			passengers = boardingHome - missed;
			boardingHome = missed;
			cout << passengers << " passengers loaded at port " << currentPort << endl;
			cout << boardingHome << " passengers remain at port " << currentPort << endl;
			cout << missed << " Passengers missed their trip!" << endl;
		}
	}
	else
	{
		if (boardingDest > capacity)
		{
			passengers = capacity;
			boardingDest -= capacity;
			cout << passengers << " passengers loaded at port " << currentPort << endl;
			cout << boardingDest << " passengers remain at port " << currentPort << endl;
		}
		else
		{
			passengers = boardingDest;
			boardingDest = 0;
			cout << passengers << " passengers loaded at port " << currentPort << endl;
			cout << boardingDest << " passengers remain at port " << currentPort << endl;
		}
	}
}

void ShuttleBoat::offloadPassengers()
{
	cout << "Offloading " << passengers << " at port " << currentPort << endl;
	passengers = 0;
}

void ShuttleBoat::changePort()
{
	if (currentPort == 1)
	{
		currentPort = destPort;
		cout << "Steaming for port " << currentPort << endl;
	}
	else
	{
		currentPort = 1;
		cout << "Steaming for port " << currentPort << endl;
	}
}

int ShuttleBoat::missChance()
{
	int random = rand() % (4 + 1);
	return random;
}