/*File Name: ListOfAges.cpp
Programmer: Joesph Olliff
Purpose: The set of methods associated with the ListOfAges Class*/

#include <iostream>
#include <fstream>
#include <math.h>
#include "ListOfAges.h"
using namespace std;


ListOfAges::ListOfAges(string file)
{
	average = 0.0;
	entries = 0;
	belowAverage = 0;
	fileName = file;
}

double ListOfAges::getAverage()
{
	return average;
}

int ListOfAges::getBelowAverage()
{
	return belowAverage;
}

int ListOfAges::getEntries()
{
	return entries;
}

string ListOfAges::getFileName()
{
	return fileName;
}

void ListOfAges::loadAges()
{
	ifstream loadFile;

	loadFile.open(fileName, ios::in);

	if (loadFile.is_open())
	{
		loadFile >> ages[0];

		while (!loadFile.eof())
		{
			entries++;

			loadFile >> ages[entries];
		}
		loadFile.close();
	}
}

void ListOfAges::displayAges()
{
	int count = 0;

	for (count = 0; count < entries; count++)
	{
		cout << "Age: " << ages[count] << endl;
	}
}

double ListOfAges::calcAverageAge()
{
	int count = 0;
	double total = 0.0;

	for (count = 0; count < entries; count++)
	{
		total += ages[count];
	}

	average = total / entries;

	return average;
}

int ListOfAges::countBelowAverage()
{
	for (int count = 0; count < entries; count++)
	{
		if (ages[count] < average)
		{
			belowAverage++;
		}
	}

	return belowAverage;
}

double ListOfAges::calcStandardDeviation()
{
	int calcArray[200];
	double total = 0.0;

	for (int count = 0; count < entries; count++)
	{
		calcArray[count] = average - ages[count];
		calcArray[count] *= calcArray[count];
		total += calcArray[count];
	}

	total = total / entries;
	total = sqrt(total);

	return total;
}