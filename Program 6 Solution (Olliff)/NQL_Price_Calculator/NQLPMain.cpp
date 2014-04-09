//FILE : NQLPMain.cpp
//PROG : Joesph Olliff
//PURP : To calculate expendatures of a series of NQL Plants

#include <fstream>
#include <istream>
#include <iomanip>
#include <array>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int **getProd(ifstream&, int[][NUM_PROD]);
int getPric(ifstream&, int array);
int numEntry(ifstream&);
ifstream& GotoLine(ifstream, unsigned int);

const int NUM_PLANTS = 3; //Static number of Plants (must change when adding Plants!)
const int NUM_PROD = 3; //Static number of Products (must change when adding Products!)
const int NUM_COMP = 5; //Static number of Components (Due to intrensic nature of the components and there use, leave this unchanged)

int main()
{
	//File reading object
	ifstream fileRead;

	//Storage and calculation arrays
	int plants[NUM_PLANTS][NUM_PROD];
	int components[NUM_COMP][NUM_PROD];
	int costs[NUM_PLANTS][NUM_PROD];

	//storage tools
	string fileName;
	int count = 0;
	int count2 = 0;
	int plaNum = 0; //used in setting the pointer in the file (leave unchanged when adding additional Plants)
	
	cout << "Please enter the name of the file (case sensitive, include file extension): "; //Get File name
	cin >> fileName; 

	if (fileName.empty()) //Verify that the user entered something
	{
		system("cls");
		cout << "Error no File Name entered... exiting... " << endl;
	}
	else
	{
		fileRead.open(fileName);
		if (fileRead.is_open()) //Check that the file was found and opened
		{
			plaNum = numEntry(fileRead); //Find the blank line indicating the end of plant info

			fileRead.close();
			fileRead.open(fileName); // close and reopen the file to reset the pointer

			getProd(fileRead, plants);
			for (count = 0; count < NUM_PLANTS; count++)
			{
				for (count2 = 0; count2 < NUM_PROD; count++)
				{
					cout << plants[count][count2] << endl;
				}
			}
			
			system("pause");
		}
		else
		{
			system("cls");
			cout << "Error File not found... exiting... " << endl;
		}
	}
	system("pause");
	return 0;
}

ifstream& GotoLine(ifstream& file, unsigned int num) //Sets the file reader to the desired position
{
	file.seekg(ios::beg);
	for (int i = 0; i < num - 1; ++i){
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

int numEntry(ifstream& file) //Determines the number of plants in the file
{
	string s;
	int entry = 0;
	while (getline(file, s))
	{
		entry++;
		if (s.empty())
		{
			break;
		}
	}
	return entry;
}

int getProd(ifstream& file, int plants[][NUM_PROD])
{
	int count, count2;

	for (count = 0; count < NUM_PLANTS; count++)
	{
		for (count2 = 0; count2 < NUM_PROD; count++)
		{
			plants[NUM_PLANTS][NUM_PROD] = 0;
		}
	}
	return plants;
}