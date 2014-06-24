/*File Name: ShuttleBoat.h
Programmer: Joesph Olliff
Purpose: A Ferry boat moving passengers back and forth between home port and a configurable target port*/

#include <iostream>
using namespace std;

class ShuttleBoat
{
private:
	string boatID;
	int currentPort;
	int destPort;
	int passengers;
	int capacity;
	int boardingHome;
	int boardingDest;

public:
	ShuttleBoat(string, int, int, int, int, int);
	string getBoatID();
	int getCurrentPort();
	int getDestPort();
	int getPassengers();
	int getCapacity();
	int getBoardingHome();
	int getBoardingDest();
	void loadPassengers();
	void loadPassengers(bool);
	void offloadPassengers();
	void changePort();
	bool missChance(int);
};