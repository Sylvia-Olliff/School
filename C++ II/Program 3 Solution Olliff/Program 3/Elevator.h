/*File Name: Elevator.h
Programmer: Joesph Olliff
Purpose: The Elevator Class simulates a physical elevator with a configurable floor range, 
		capacity, and contains safe movement and boarding methods */

#include <iostream>

using namespace std;

class Elevator
{
private:
	int capacity;
	int passengers;
	int lowestFloor;
	int highestFloor;
	int currentFloor;
	int destinationFloor;

public:
	Elevator(int, int, int, int);
	int getCapacity();
	int getPassangers();
	int getLowestFloor();
	int getHighestFloor();
	int getCurrentFloor();
	int getDestinationFloor();
	void loadPassengers(int);
	void offloadPassengers(int);
	void changeFloors(int);
};

Elevator::Elevator(int maxCap, int lowFloor, int highFloor, int curntFloor)
{
	capacity = maxCap;
	passengers = 0;
	lowestFloor = lowFloor;
	highestFloor = highFloor;
	currentFloor = curntFloor;
	destinationFloor = curntFloor;
}

int Elevator::getCapacity()
{
	return capacity;
}

int Elevator::getCurrentFloor()
{
	return currentFloor;
}

int Elevator::getDestinationFloor()
{
	return destinationFloor;
}

int Elevator::getHighestFloor()
{
	return highestFloor;
}

int Elevator::getLowestFloor()
{
	return lowestFloor;
}

int Elevator::getPassangers()
{
	return passengers;
}

void Elevator::loadPassengers(int passBoarding)
{
	if (passBoarding + passengers <= capacity)
	{
		passengers += passBoarding;
		cout << passBoarding << " Passengers boarded the Elevator for a total of " << passengers << " Passengers" << endl;
	}
	else
	{
		int overflow = 0;
		overflow = (passBoarding + passengers) - capacity;
		passBoarding -= overflow;
		passengers = capacity; // extra passengers never get on the Elevator insuring that it is never overloaded.... not even for a nanosecond...
		cout << passBoarding << " Passengers boarded the Elevator for a total of " << passengers << " Passengers" << endl; 
		cout << overflow << " Passengers were unable to board, the Elevator is at Capacity!" << endl;
	}
}

void Elevator::offloadPassengers(int passLeaving)
{
	if (passLeaving <= passengers)
	{
		passengers -= passLeaving;
		cout << passLeaving << " Passengers left the elevator leaving " << passengers << " Passengers behind" << endl;
	}
	else
	{
		passLeaving = passengers; // ensures that passengers is never assigned a negative value
		passengers = 0;
		cout << passLeaving << " Passengers left the elevator leaving " << passengers << " Passengers behind" << endl;
	}
}

void Elevator::changeFloors(int targetFloor)
{
	if (targetFloor <= highestFloor && targetFloor >= lowestFloor && targetFloor != currentFloor)
	{
		destinationFloor = targetFloor;
		cout << "Leaving Floor " << currentFloor << endl;
		if (destinationFloor > currentFloor)
		{
			while (destinationFloor - 1 != currentFloor)
			{
				currentFloor++;	
				cout << "Passing Floor " << currentFloor << endl;
			}
			currentFloor++;
			cout << "Arriving at Floor " << currentFloor << endl;
		}
		else
		{
			while (destinationFloor + 1 != currentFloor)
			{
				currentFloor--;
				cout << "Passing Floor " << currentFloor << endl;
			}
			currentFloor--;
			cout << "Arriving at Floor " << currentFloor << endl;
		}
	}
	else
	{
		cout << "Invalid Floor, please try again..." << endl;
	}
}