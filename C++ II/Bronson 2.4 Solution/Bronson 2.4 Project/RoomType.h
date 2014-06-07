#include <iostream>
using namespace std;

class RoomType
{
	//Data declaration section  
private:
	double length;  //Declare length as a double variable
	double width;   //Declare width as a double variable 
	int height;

	//Methods declaration section  
public:
	RoomType(); //The constructor's declaration statement
	void showRoomValues();
	void setNewRoomValues();
	void calculateRoomArea();
	void displayVolumeOfRoom();
};

//Methods implementation section
RoomType::RoomType()  //This is a constructor
{
	length = 25.0;
	width = 12.0;
	height = 9;
	cout << "Created a new room object using the default constructor.\n\n"; // PROFESSOR: Does this really count as the "default" constructor if we are defining what it does here?
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

void RoomType::displayVolumeOfRoom()
{
	cout << length * width * height;
}

