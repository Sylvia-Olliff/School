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
	system("cls");
	elevatorOne.changeFloors(60);
	system("pause");
	system("cls");
	elevatorOne.offloadPassengers(7);
	system("pause");
	system("cls");
	elevatorOne.changeFloors(1000);
	system("pause");
	system("cls");
	elevatorOne.loadPassengers(20);
	system("pause");
	system("cls");
	elevatorOne.changeFloors(35);
	system("pause");
	system("cls");
	elevatorOne.offloadPassengers(3);
	system("pause");
	system("cls");
	elevatorOne.changeFloors(-5);
	system("pause");
}