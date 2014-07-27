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
void formattedDisplay(int,int,StoreInventory&);
void formattedCloseout(int, int);

int main()
{
	int choice = 0;
	int itemID = 0;
	int searchResult = 0;
	int itemFound = 0;
	int quantity = 0;
	int queryCount = 0;
	int itemFoundCount = 0;
	bool done = false;
	double priceFound = 0.0;
	string file;

	cout << "Search Pro 2000: Allows you to look up any item in the master inventory and calculate prices " << endl << endl;

	cout << "Please enter the inventory file name: ";
	cin >> file;
	system("cls");

	StoreInventory inventory(file);

	inventory.loadArray();
	inventory.sortArray();
	
	while (!done)
	{
		choice = menu();

		switch (choice)
		{
		case 1:
			cout << "Please enter the item ID: ";
			cin >> itemID;
			queryCount++;
			searchResult = inventory.seqSearch(itemID);
			if (searchResult != -1)
			{
				itemFound = inventory.getIdNum(searchResult);
				priceFound = inventory.getPrice(searchResult);
				cout << setprecision(2) << fixed;
				cout << "Sequential search found " << itemFound << " it costs " << priceFound << endl;
			}
			else
			{
				cout << "Sequential search did not find the item! " << endl;
			}

			searchResult = inventory.binSearch(itemID);
			if (searchResult != -1)
			{
				itemFoundCount++;
				itemFound = inventory.getIdNum(searchResult);
				priceFound = inventory.getPrice(searchResult);
				cout << setprecision(2) << fixed;
				cout << "Binary search found " << itemFound << " it costs " << priceFound << endl << endl;
				cout << "Please enter how many of these items are being purchased: ";
				cin >> quantity;
				formattedDisplay(searchResult, quantity, inventory);
			}
			else
			{
				cout << "Binary search did not find the item! " << endl;
			}
			system("pause");
			system("cls");
			break;

		case 2:
			formattedCloseout(queryCount, itemFoundCount);
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

void formattedDisplay(int location, int total, StoreInventory& inventory)
{
	int item = 0;
	double price = 0.0;
	double totPrice = 0.0;

	item = inventory.getIdNum(location);
	price = inventory.getPrice(location);

	totPrice = price * total;

	cout << setprecision(2) << fixed;
	cout << "itemID" << setw(9) << "price" << setw(10) << "quantity" << setw(10) << "total" << endl;
	cout << item << setw(10) << price << setw(10) << total << setw(10) << totPrice << endl;
}

void formattedCloseout(int query, int success)
{
	cout << "total searches" << setw(15) << "items found" << setw(20) << "items not found" << endl;
	cout << "     " << query << setw(18) << success << setw(17) << query - success << endl << endl;
}