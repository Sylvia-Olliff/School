/*File Name: FerryBoat.cpp
Programmer: Joesph Olliff
Purpose: Methods and operations for the FerryBoat*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "FerryBoat.h"
using namespace std;

FerryBoat::FerryBoat(int numPortsOnRoute, int maxCapacity, int startingPortNum, string shipID)
{
	boatID = shipID;
	numPorts = numPortsOnRoute;
	if (startingPortNum < numPorts) //Verify that the starting port is within the range of the number of ports
	{
		currentPort = startingPortNum;
		destPort = startingPortNum;
	}
	else
	{
		cout << "Error initializing starting port, defaulting to final port...\n";
		currentPort = numPorts;
		destPort = numPorts;
	}
	passengers = 0;
	capacity = maxCapacity;
	srand(time(NULL)); //seed random number gen
}

string FerryBoat::getBoatID()
{
	return boatID;
}

int FerryBoat::getCapacity()
{
	return capacity;
}

int FerryBoat::getCurrentPort()
{
	return currentPort;
}

int FerryBoat::getDestPort()
{
	return destPort;
}

int FerryBoat::getNumPorts()
{
	return numPorts;
}

int FerryBoat::getPassengers()
{
	return passengers;
}

int FerryBoat::genRandomNum(int maxValue)
{
	int random = rand() % (maxValue + 1);//generates a number between 0 and  maxValue to include maxValue

	return random;
}

void FerryBoat::loadPassengers()
{
	int loading = genRandomNum(200);
	if (loading + passengers < capacity) //Make sure capacity is never exceeded
	{
		cout << loading << " Passengers boarded for a total of ";
		passengers += loading;
		cout << passengers << " on board.\n";
	}
	else
	{
		int leftover = (loading + passengers) - capacity; //capture number of people left behind
		passengers = capacity;
		loading -= leftover;
		cout << loading << " Passengers boarded for a total of " << passengers << " on board. \nThe "
			<< boatID << " is at capacity! " << leftover << " passengers were left behind. \n";
	}
}

void FerryBoat::loadPassengers(bool morePass) //Overloaded and modified to show effects of being delayed
{
	int loading = genRandomNum(200);
	loading = loading + (loading * 0.15);
	cout << "There was an issue during that last trip, the ship was delayed!\n";
	if (loading + passengers < capacity)
	{
		cout << loading << " Passengers boarded for a total of ";
		passengers += loading;
		cout << passengers << " on board.\n";
	}
	else
	{
		int leftover = (loading + passengers) - capacity;
		passengers = capacity;
		loading -= leftover;
		cout << loading << " Passengers boarded for a total of " << passengers << " on board. \nThe "
			<< boatID << " is at capacity! " << leftover << " passengers were left behind. \n";
	}
}

void FerryBoat::offloadPassengers()
{
	int offloading = genRandomNum(passengers); //number generated will always be less than or equal to number of passengers
	passengers -= offloading;
	cout << offloading << " passengers disembarked leaving a total of " << passengers << " still on board.\n";
}

void FerryBoat::changePort(int destinationPort)
{
	bool delayed = false;
	if (destinationPort <= numPorts && destinationPort > 0 && destinationPort != currentPort)
	{
		destPort = destinationPort;
		cout << "Departing port " << currentPort << " heading for port " << currentPort+1 << endl;
		delayed = delayChance();
		while (destPort - 1 != currentPort)//Heading out to destination stopping at each port
		{
			currentPort++;
			cout << "Stopping at port " << currentPort << endl;
			if (delayed)
			{
				offloadPassengers();
				loadPassengers(delayed);
			}
			else
			{
				offloadPassengers();
				loadPassengers();
			}
			delayed = delayChance();
			cout << "Departing port " << currentPort << " heading for port " << currentPort+1 << endl;
		}
		currentPort++;
		cout << "Arriving at Destination port " << currentPort << endl;
		offloadPassengers();
		loadPassengers();

		cout << "Returning to Home Port\n";
		cout << "Arriving at Home Port\n";
		currentPort = 1;
		destPort = 1;
		offloadPassengers();
		
	}
	else
	{
		cout << "Error, unable to set destination. Invalid Destination\n\n";
		system("pause");
	}
}

bool FerryBoat::delayChance()
{
	int chance = genRandomNum(10);
	if (chance == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}