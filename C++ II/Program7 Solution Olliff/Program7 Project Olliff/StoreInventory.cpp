/*File Name: StoreInventory.cpp
Programmer: Joesph Olliff
Purpose: The set of methods associated with the StoreInventory Class, used to search a file of book entries
and prices using a binary search algorithm after sorting data from a file.*/

#include <iostream>
#include <fstream>
#include "StoreInventory.h"
using namespace std;

StoreInventory::StoreInventory(string file)
{
	fileName = file;
	entries = 0;
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

void StoreInventory::sortArray()
{
	int last = entries - 1;
	int ind = 0;
	int swap = 0;
	int tempID = 0;
	double tempPrice = 0.0;

	while (last > 0)
	{
		ind = 0;
		swap = 0;

		while (ind < last)
		{
			if (idNum[ind] > idNum[ind + 1])
			{
				tempID = idNum[ind];
				idNum[ind] = idNum[ind + 1];
				idNum[ind + 1] = tempID;

				tempPrice = price[ind];
				price[ind] = price[ind + 1];
				price[ind + 1] = tempPrice;

				swap = 1;
			}

			ind++;
		}

		if (swap == 0)
		{
			last = 0;
		}
		else
		{
			last--;
		}
	}
}

int StoreInventory::seqSearch(int search)
{

	int count = 0;

	while (count <= entries)
	{
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


