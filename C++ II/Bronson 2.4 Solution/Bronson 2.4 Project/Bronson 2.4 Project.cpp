//FILE : Bronson 2.4 Project.cpp
//PROG : Dave Jones (with help of Bronson's text)
//PURP : This is the Bronson textbook Program 2.4 (pp 109 - 110)
//Note:  this program has the class defined in the same file as main
//In your programs the class will usually be defined in a separate header file

#include <iostream>
using namespace std;

class RoomType
{
  //Data declaration section  
  private: 
    double length;  //Declare length as a double variable
    double width;   //Declare width as a double variable 

  //Methods declaration section  
  public:
    RoomType(); //The constructor's declaration statement
    void showRoomValues();
    void setNewRoomValues();
    void calculateRoomArea();
};

//Methods implementation section
RoomType::RoomType()  //This is a constructor
{
  length = 25.0;
  width = 12.0;
  cout << "Created a new room object using the default constructor.\n\n";
} 

void RoomType::showRoomValues()   //This is an accessor
{
  cout << "  length = " << length 
       << "\n  width = " << width << endl;
}

void RoomType::setNewRoomValues()   //This is a mutator 
{  
  length = 12.5;
  width = 9.0;
}

void RoomType::calculateRoomArea()  //This performs a calculation
{    
  cout << length * width;
}

int main()
{
  RoomType roomOne;  //Declare a variable of type RoomType

  cout << "The values for this room are:\n";
  roomOne.showRoomValues();       //Use a class method on this object
  cout << "\nThe floor area of this room is: ";
  roomOne.calculateRoomArea();    //Use another class method on this object
 
  roomOne.setNewRoomValues();   //Call the mutator
  
  cout << "\n\nThe values for this room have been changed to:\n";
  roomOne.showRoomValues();
  cout << "\nThe floor area of this room is: ";
  roomOne.calculateRoomArea();

  cout << endl;
  return 0;
}
