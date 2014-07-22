/*File Name: StoreInventory.h
Programmer: Joesph Olliff
Purpose: StoreInventory Class used to describe an Inventory object used in performing searches 
			with sequential and binary algorithms.*/

#include <iostream>
using namespace std;

class StoreInventory
{
private:
	int idNum[200];
	double price[200];
	string fileName;
	int entries;
	int comparisonCount;

public:
	StoreInventory(string);
	void loadArray();
	int seqSearch(int);
	int binSearch(int);
	int getIdNum(int);
	double getPrice(int);
	void resetCompare();
	int getCompareCount();
};