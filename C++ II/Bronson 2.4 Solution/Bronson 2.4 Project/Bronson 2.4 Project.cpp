//FILE : Bronson 2.4 Project.cpp
//PROG : Joesph Olliff
//PURP : To define, calculate, and describe the geometric aspects of a room.

#include <iostream>
#include "RoomType.h"
using namespace std;


int main()
{
  RoomType roomOne;  //Declare a variable of type RoomType

  cout << "The values for this room are:\n";
  roomOne.showRoomValues();       //Use a class method on this object
  cout << "\nThe floor area of this room is: ";
  roomOne.calculateRoomArea();    //Use another class method on this object
  cout << "\nThe Volume of the room is: ";
  roomOne.displayVolumeOfRoom();
 
  cout << endl << endl;

  system("pause");
  system("cls");
  roomOne.setNewRoomValues();   //Call the mutator
  
  cout << "The values for this room have been changed to:\n";
  roomOne.showRoomValues();
  cout << "\nThe floor area of this room is: ";
  roomOne.calculateRoomArea();
  cout << "\nThe Volume of the room is: ";
  roomOne.displayVolumeOfRoom();

  cout << endl << endl;
  system("pause");
  return 0;
}
