/*File Name: ListOfAges.h
Programmer: Joesph Olliff
Purpose: class for creating a file processing object*/

#include <iostream>
using namespace std;

class ListOfAges {

private:
	int ages[200];
	int average;
	int entries;
	int belowAverage;
	string fileName;

public:
	ListOfAges(string);
	int getAverage();
	int getEntries();
	int getBelowAverage();
	string getFileName();
	void loadAges();
	void displayAges();
	int calcAverageAge();
	int countBelowAverage();
	double calcStandardDeviation();
};