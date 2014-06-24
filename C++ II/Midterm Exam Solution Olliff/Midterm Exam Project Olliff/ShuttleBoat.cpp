/*File Name: ShuttleBoat.cpp
Programmer: Joesph Olliff
Purpose: Method set for the ShuttleBoat*/

#include <iostream>
#include <string>
#include <iomanip>
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

}

void ShuttleBoat::loadPassengers(bool missed)
{

}

void ShuttleBoat::offloadPassengers()
{

}

void ShuttleBoat::changePort()
{

}

bool ShuttleBoat::missChance(int max)
{
	bool chance = false;

	return chance;
}