/*File Name: StoreInventory.h
Programmer: Joesph Olliff
Purpose: StoreInventory Class used to describe an Inventory object used in performing searches 
			with a binary algorithm after sorting data from a file.*/

#include <iostream>
using namespace std;

class StoreInventory
{
private:
	int idNum[200];
	double price[200];
	string fileName;
	int entries;

public:
	StoreInventory(string);
	void loadArray();
	void sortArray();
	int binSearch(int);
	int getIdNum(int);
	double getPrice(int);
	int seqSearch(int);
};