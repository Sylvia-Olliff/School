/*File Name: InventorySearchMain.cpp
Programmer: Joesph Olliff
Purpose: Main Controller for an inventory search program using both binary and 
			sequential search algorithms.*/

#include <iostream>
#include <iomanip>
#include <string>
#include "StoreInventory.h"

using namespace std;

int menu();

int main()
{
	int choice = 0;
	int itemID = 0;
	int searchResult = 0;
	int itemFound = 0;
	int comparisons = 0;
	bool done = false;
	double priceFound = 0.0;
	string file;

	cout << "Please enter the inventory file name: ";
	cin >> file;
	system("cls");

	StoreInventory inventory(file);

	inventory.loadArray();

	while (!done)
	{
		choice = menu();

		switch (choice)
		{
		case 1:
			cout << "Please enter the item ID: ";
			cin >> itemID;
			searchResult = inventory.seqSearch(itemID);
			comparisons = inventory.getCompareCount();
			inventory.resetCompare();
			if (searchResult != -1)
			{
				itemFound = inventory.getIdNum(searchResult);
				priceFound = inventory.getPrice(searchResult);
				cout << "Sequential search found " << itemFound << " it costs " << priceFound << endl;
				cout << "This search took " << comparisons << " comparisons." << endl;
			}
			else
			{
				cout << "Sequential search did not find the item! " << endl;
			}
			searchResult = inventory.binSearch(itemID);
			comparisons = inventory.getCompareCount();
			inventory.resetCompare();
			if (searchResult != -1)
			{
				itemFound = inventory.getIdNum(searchResult);
				priceFound = inventory.getPrice(searchResult);
				cout << "Binary search found " << itemFound << " it costs " << priceFound << endl;
				cout << "This search took " << comparisons << " comparisons." << endl;
			}
			else
			{
				cout << "Binary search did not find the item! " << endl;
			}
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Thank you for using Search Pro 2000!" << endl;
			system("pause");
			done = true;
			break;

		default:
			cout << "Invalid entry please try again..." << endl;
			system("pause");
			break;
		}
	}
	return 0;
}

int menu()
{
	int selection = 0;
	cout << "1. Perform Search\n2. Exit\n";
	cin >> selection;

	system("cls");
	return selection;
}