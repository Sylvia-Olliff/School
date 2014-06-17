/*File Name: ElevatorControl.cpp
Programmer: Joesph Olliff
Purpose: A control program simulating the motions of an elevator */

#include <iostream>

#include "Elevator.h"

using namespace std;

int main()
{
	Elevator elevatorOne(18,1,99,1);
	

	//Simulates a test run covering normal functionality as well as stress test for error checking
	elevatorOne.loadPassengers(5);
	system("pause");
	elevatorOne.changeFloors(60);
	system("pause");
	elevatorOne.offloadPassengers(7);
	system("pause");
	elevatorOne.changeFloors(1000);
	system("pause");
	elevatorOne.loadPassengers(20);
	system("pause");
	elevatorOne.changeFloors(35);
	system("pause");
	elevatorOne.offloadPassengers(3);
	system("pause");
	elevatorOne.changeFloors(-5);
	system("pause");
	elevatorOne.changeFloors(78);
	system("pause");
	elevatorOne.offloadPassengers(6);
	system("pause");
	elevatorOne.changeFloors(98);
	system("pause");
	elevatorOne.loadPassengers(4);
	system("pause");
	elevatorOne.changeFloors(21);
	system("pause");
	elevatorOne.offloadPassengers(7);
	system("pause");
	elevatorOne.changeFloors(1);
	system("pause");
	elevatorOne.loadPassengers(10);
	system("pause");

	return 0;
}