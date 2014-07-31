/*File Name: StoredOrders.cpp
Programmer: Joesph Olliff
Purpose: The set of methods associated with the StoredOrders class, used to store orders data into a file. */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "StoredOrders.h"

using namespace std;

StoredOrders::StoredOrders(string storageFile)
{
	file = storageFile;
	fileOpenSuccess = false;
	append = fileExists();
}

bool StoredOrders::fileExists()
{
	ifstream f(file);

	if (f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StoredOrders::openOutputFile()
{
	if (append)
	{
		o.open(file, ios::app);
		if (!o.is_open())
		{
			cout << "There was an error opening the file..." << endl;
			system("pause");
		}
		else
		{
			fileOpenSuccess = true;
		}
	}
	else
	{
		o.open(file);
		if (!o.is_open())
		{
			cout << "There was an error creating the file..." << endl;
			system("pause");
		}
		else
		{
			append = true;
			fileOpenSuccess = true;
		}
	}
}

bool StoredOrders::getFileOpenStatus()
{
	return fileOpenSuccess;
}

void StoredOrders::saveOneRecord(int ID, int quantity, double total)
{
	openOutputFile();
	o << ID << " " << quantity << " " << total << '\n';
	closeOutputFile();
}

void StoredOrders::closeOutputFile()
{
	o.close();
	fileOpenSuccess = false;
}

void StoredOrders::displayAllOrders()
{
	int ID[200], quantity[200];
	double total[200];
	int count = 0;

	f.open(file);
	if (f.is_open)
	{
		while (!f.eof())
		{
			f >> ID[count];
			f >> quantity[count];
			f >> total[count];

			count++;
		}
		f.close();
	}
	

	cout << setprecision(2) << fixed;
	cout << "ID Number" << setw(14) << "Quantity" << setw(14) << "Total Cost" << endl;
	for (int i = 0; i < count-1; i++)
	{
		cout << ID[i] << setw(14) << quantity[i] << setw(14) << total[i] << endl;
	}

}

double StoredOrders::calcTotalCostOfOrders()
{
	double totalCost = 0.0;
	int ID[200], quantity[200];
	double total[200];
	int count = 0;

	f.open(file);
	if (f.is_open)
	{
		while (!f.eof())
		{
			f >> ID[count];
			f >> quantity[count];
			f >> total[count];

			count++;
		}
		f.close();
	}
	

	for (int i = 0; i < count-1; i++)
	{
		totalCost += total[i];
	}

	return totalCost;
}