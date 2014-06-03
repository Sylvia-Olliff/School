/*File Name: BankAccountManager.cpp
  Programmer: Joesph Olliff
  Purpose: To create and alter Savings Accounts. */

#include <iostream>
#include <string>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

void welcome();
int menuRec();
int menuNew();



int main()
{
	double bankBalance = 0.0;
	int count = 0;
	int selection = 0;
	int newCust = 0;

	SavingsAccount accountOne(1000.00,0.003,"005523457","1337",2);

	welcome();


	system("pause");
	return 0;
}

void welcome()
{
	cout << "Welcome to BankPro 1.0" << endl << endl;
}

int menuRec()
{
	int selec;
	cout << "Please make a selection from the following menu: " << endl;
	cout << "1. Make a Deposit" << endl;
	cout << "2. Make a Withdrawal" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Selection: ";
	cin >> selec;

	return selec;
}