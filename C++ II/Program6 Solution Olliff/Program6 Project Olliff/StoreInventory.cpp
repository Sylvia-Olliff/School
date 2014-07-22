/*File Name: StoreInventory.cpp
Programmer: Joesph Olliff
Purpose: The set of methods associated with the StoreInventory Class, used to search a file of book entries 
			and prices using sequential and binary search algorithms*/

#include <iostream>
#include <fstream>
#include "StoreInventory.h"
using namespace std;

StoreInventory::StoreInventory(string file)
{
	fileName = file;
	entries = 0;
	comparisonCount = 0;
}
 
void StoreInventory::loadArray()
{
	ifstream loadFile;

	loadFile.open(fileName, ios::in);

	if (loadFile.is_open())
	{
		loadFile >> idNum[0];
		loadFile >> price[0];

		while (!loadFile.eof())
		{
			entries++;

			loadFile >> idNum[entries];
			loadFile >> price[entries];
		}
		loadFile.close();
	}
}

int StoreInventory::seqSearch(int search)
{

	int count = 0;

	while (count <= entries)
	{
		comparisonCount++;
		if (search == idNum[count])
		{
			return count;
		}
		count++;
	}

	return -1;
}

int StoreInventory::binSearch(int search)
{
	int first = 0;
	int last = entries - 1;
	int found = 0;
	int mid = 0;

	while (first <= last && found == 0)
	{
		mid = (first + last) / 2;
		if (idNum[mid] == search)
		{
			found = 1;
		}
		else if (idNum[mid] < search)
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
		comparisonCount++;
	}

	if (found == 0)
	{
		mid = -1;
	}

	return mid;
}

int StoreInventory::getIdNum(int location)
{
	return idNum[location];
}

double StoreInventory::getPrice(int location)
{
	return price[location];
}

void StoreInventory::resetCompare()
{
	comparisonCount = 0;
}

int StoreInventory::getCompareCount()
{
	return comparisonCount;
}