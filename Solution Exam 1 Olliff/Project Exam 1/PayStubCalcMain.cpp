/********************************************************************************************************
*   FILENAME: 	PayStubClacMain.cpp																		*
*   PROGRAMMER: Joesph Olliff 2/17/14																	*
*   PURPOSE:	To Calculate an employee's net pay factoring in the total hours worked along with		*
*				the number of dependents and taxes witheld												*
*********************************************************************************************************/

#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

void welcome(string intro)
{
	cout << "Thank you for using " + intro + " version 1.0" << endl << endl;
}

void payStub(string last, string first, string ssn, int dep, double payRate,
	int hours, double netPay, double grossPay, double deduc)
{
	cout.precision(2);
	cout << fixed << showpoint;
	system("cls");
	cout << "*************************************************************" << endl;
	cout << "Employee Name: " << last << ", " << first << endl << endl;
	cout << "SSN: " << ssn << "        Number of Dependents: " << dep << endl;
	cout << "*************************************************************" << endl;
	cout << "Pay Rate:  " << payRate << "         Hours: " << hours << endl;
	cout << "Gross Pay: " << grossPay << "       Total Deductions: " << deduc << endl;
	cout << "Net Pay:   " << netPay << endl;
	cout << "*************************************************************" << endl << endl << endl;
}

int main()
{
	//Employee Attributes
	string nameFirst = "";
	string nameLast = "";
	double hours = 0.0;
	double payRate = 0.0;
	int depen = 0;
	long social = 0;
	string socialOut = "";

	//data integrity tools
	bool exit = false;

	//conversion tools
	ostringstream convert;

	//Calculated Values
	double grossPay = 0.0;
	double netPay = 0.0;
	double amountDed = 0.0;

	//Constant Values
	const double TAX_RATE = 0.17;
	const double DEPENDANT_DEDUC = 15.00;
	const string LABEL = "Pay Calculator";

	//Welcome Message
	welcome(LABEL);

	//Gather Employee Information
	cout << "Please enter Employee First Name: ";
	cin >> nameFirst;
	
	cout << endl << endl;

	cout << "Please enter Employee Last Name: ";
	cin >> nameLast;

	cout << endl << endl;

	do //Verify 9 digit social security number is entered
	{
		cout << "Please enter Employee SSN with no dashes: ";
		cin >> social;
		if (social > 999999999 || social < 100000000)
		{
			system("cls");
			cout << "Please enter a valid SSN " << endl;
			system("pause");
		}
		else
		{
			exit = true;
		}
	} while (!exit);

	//convert to String and insert dashes
	convert << social;
	socialOut = convert.str();
	socialOut.insert(3, 1, '-');
	socialOut.insert(6, 1, '-');

	cout << endl << endl;

	cout << "Please enter the Employee's hourly pay rate: ";
	cin >> payRate;

	cout << endl << endl;

	cout << "Please enter the number of hours worked this pay period: ";
	cin >> hours;

	cout << endl << endl;

	cout << "Please enter the number of listed dependants for the Employee: ";
	cin >> depen;

	//perform calculations
	grossPay = payRate * static_cast<double>(hours);
	amountDed = grossPay*TAX_RATE - static_cast<double>(depen)*DEPENDANT_DEDUC;
	netPay = grossPay - amountDed;

	//Display Pay Report
	payStub(nameLast, nameFirst, socialOut, depen, payRate,
		hours, netPay, grossPay, amountDed);

	system("pause");
	return 0;
}