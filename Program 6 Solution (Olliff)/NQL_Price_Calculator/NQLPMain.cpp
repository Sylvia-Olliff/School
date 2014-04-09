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

int getProd(ifstream&);
int getPric(ifstream&);
int numEntry(ifstream&);
ifstream& GotoLine(ifstream, unsigned int);

const int numPlants = 1;
const int typeProd = 3;

int main()
{
	ifstream fileRead;

	string plaName[50];
	string fileName;
	int count = 0;
	int plaNum = 0;
	
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
			plaNum = numEntry(fileRead);
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