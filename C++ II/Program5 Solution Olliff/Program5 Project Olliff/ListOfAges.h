/*File Name: ListOfAges.h
Programmer: Joesph Olliff
Purpose: class for creating a file processing object*/

#include <iostream>
using namespace std;

class ListOfAges {

private:
	int ages[200];
	double average;
	int entries;
	int belowAverage;
	string fileName;

public:
	ListOfAges(string);
	double getAverage();
	int getEntries();
	int getBelowAverage();
	string getFileName();
	void loadAges();
	void displayAges();
	double calcAverageAge();
	int countBelowAverage();
	double calcStandardDeviation();
};