/*File Name: FerryBoat.h
Programmer: Joesph Olliff
Purpose: A Ferry boat moving passengers along a configurable route of ports*/

#include <iostream>
using namespace std;

class FerryBoat
{
private:
	string boatID;
	int currentPort;
	int destPort;
	int numPorts;
	int passengers;
	int capacity;

public:
	FerryBoat(int,int,int,string);
	string getBoatID();
	int getCurrentPort();
	int getDestPort();
	int getNumPorts();
	int getPassengers();
	int getCapacity();
	int genRandomNum(int);
	bool delayChance();
	void loadPassengers();
	void loadPassengers(bool);
	void offloadPassengers();
	void changePort(int);

};