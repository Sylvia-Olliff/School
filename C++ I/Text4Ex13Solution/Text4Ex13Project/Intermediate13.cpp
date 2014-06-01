//Intermediate13.cpp - displays the gallons of water used and the total water charge
//Created/revised by Joesph Olliff on 02/21/14

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables and named constants
	int current  = 0;
	int previous = 0;
	int gallons  = 0;
	double total = 0.0;
	const double CHG_PER_GAL = .007;
	const double MINIMUM_CHG = 16.67;

	//enter input items
	cout << "Current reading: ";
	cin >> current;
	cout << "Previous reading: ";
	cin >> previous;

	//calculate gallons used and total charge
	gallons = current - previous;
	total = gallons * CHG_PER_GAL;

	//determine whether total charge is at least the minimum
	if (total < MINIMUM_CHG)
	{
		total = MINIMUM_CHG;
	}
	//end if

	//display gallons used and total charge
	system("cls");
	cout << fixed;
	cout << "Total Gallons Used:     " << gallons << endl;
	cout << "Total charge for usage: " << setprecision(2) << total << endl << endl;

	system("pause");
	return 0;
}	//end of main function
