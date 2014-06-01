/********************************************************************************************************
*   FILENAME: 	Discount-Main.cpp																		*
*   PROGRAMMER: Joesph Olliff 2/4/14																	*
*   PURPOSE:	To calculate the total cost of a provided item with a set discount for a hardware store	*
*********************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//static discount amount
	const double DISCOUNT = 0.35;

	//customer service variable
	int year = 0;
	string firstName = "";

	//item attributes
	double itemPrice = 0.0;
	int itemQuant = 0;
	double itemTotal = 0.0;
	string itemName = "";

	//Welcome message
	cout << "Thank you for using Hardware Discount Calc Pro. " << endl << "Please enter your First Name: ";
	cin >> firstName;
	system("cls");

	//Customer service message
	cout << "Thank you! " << endl << endl << "How many years have you been in the lowcountry? " << endl;
	cin >> year;
	system("cls");

	//Get Item Name
	cout << "Please enter the name of the item you wish to purchase: ";
	cin >> itemName;
	system("cls");

	//Get Item Price
	cout << "Please enter the original listed price for " << itemName << ": ";
	cin >> itemPrice;
	system("cls");

	//Get Item Quantity
	cout << "Please enter the number of " << itemName << " you would like to purchase: ";
	cin >> itemQuant;
	system("cls");

	//Calculate Total Price of items
	itemTotal = (itemPrice - (itemPrice * DISCOUNT)) * itemQuant;

	//Begin response
	if (year < 3)
	{
		cout << "Wow " << year << " years? relatively new to the area, I hope your enjoying it so far. " << endl << endl;
	}
	else
	{
		cout << "Wow " << year << " years? You've been here almost as long as I have, surprised I haven't seen you before. " << endl << endl;
	}

	cout << "Thank you for your purchase " << firstName << endl << "You purchased " << itemQuant << " " << itemName << endl
		<< "Which were originally priced at " << itemPrice << " but has been discounted down to " << itemPrice - (itemPrice * DISCOUNT) << endl
		<< "Your total discounted price before tax is: " << itemTotal << endl << endl << endl;

	system("pause");
	return 0;

}