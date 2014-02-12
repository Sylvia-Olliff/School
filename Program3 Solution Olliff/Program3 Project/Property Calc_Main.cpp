/********************************************************************************************************
*   FILENAME: 	Property Calc_Main.cpp																	*
*   PROGRAMMER: Joesph Olliff 2/11/14																	*
*   PURPOSE:	To Calculate the total area of the users property including the House, Pool, and the	*
*				Property itself. Includes cost of Sod for Sodded Area.									*
*********************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//User Name
	string name = "";
	//Property attributes
	int propLen = 0;
	int propWid = 0;
	int propAre = 0;
	//Pool attributes
	double poolDiaMax = 0.0;
	double poolDia = 0.0;
	double poolAre = 0.0;
	int poolDep = 0;
	double gallonsNeed = 0.0;
	double poolVol = 0.0;
	//House attributes
	int housLen = 0;
	int housWid = 0;
	int housAre = 0;
	//Constant values
	const double POOL_MAX_DIAM_PERC = 0.85;
	const double SOD_PRICE = 1.39;
	const int INCH_PER_FOOT = 12;
	const int INCH_PER_GAL = 231;
	//Final calculation values
	double totalAreaSod = 0.0;
	long double totalCost = 0.0;

	//Welcome Message
	cout << "Thank you for using Property Calculator v1.0 " << endl << endl;
	cout << "Please enter your First Name: ";
	cin >> name;
	system("cls");

	cout << "Thank you, " << name << endl << "Please enter the length of the property in feet: ";
	cin >> propLen;
	system("cls");

	cout << "Thank you, " << name << endl << "Please enter the width of the property in feet: ";
	cin >> propWid;
	system("cls");

	cout << "Thank you, " << name << endl << "Please enter the length of the house in feet: ";
	cin >> housLen;
	system("cls");

	cout << "Thank you, " << name << endl << "Please enter the width of the house in feet: ";
	cin >> housWid;
	system("cls");

	poolDiaMax = propWid - (propWid * POOL_MAX_DIAM_PERC);
	
	cout << "Due to your area's zoning laws " << name << " the maximum diameter of your pool is: " << poolDiaMax << endl << endl;
	cout << "Please enter the diameter of your pool in feet: ";
	cin >> poolDia;
	system("cls");

	cout << "Thank you, " << name << endl << "Please enter the depth of your pool in feet: ";
	cin >> poolDep;
	system("cls");

	cout.precision(2);
	propAre = propLen * propWid;
	poolAre = 3.1415 * (pow(poolDia/2, 2.0));
	housAre = housLen * housWid;
	totalAreaSod = propAre - poolAre - housAre;
	totalCost = totalAreaSod * SOD_PRICE;
	poolVol = poolAre * poolDep;
	gallonsNeed = (poolVol * INCH_PER_FOOT) / INCH_PER_GAL;

	cout << fixed << showpoint;
	cout << "Thank you " << name << endl << endl;
	cout << "Please note all dimensions are in feet:" << endl << endl;
	cout << "Area of the property: " << propAre << " length: " << propLen << " width: " << propWid << endl;
	cout << "Area of the house: " << housAre << " length: " << housLen << " width: " << housWid << endl;
	cout << "Area of the pool: " << poolAre << " diameter: " << poolDia << " depth: " << poolDep << endl;
	cout << "Total amount of water needed to fill the pool: " << gallonsNeed << " gallons" << endl << endl;
	cout << "The total area to be soded: " << totalAreaSod << endl;
	cout << "Cost of soding: " << totalCost << " at " << SOD_PRICE << " per square foot." << endl;
	cout << "Thank you for using Property Calculator v1.0 " << endl << endl;
	system("pause");

	return 0;
}