/*File Name: BankAccountManager.cpp
  Programmer: Joesph Olliff
  Purpose: To create and alter Savings Accounts. */

#include <iostream>
#include <string>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

void welcome();
void menuRec();
void menuNew();
void menuDeposit(SavingsAccount&);
void menuWithdraw(SavingsAccount&);



int main()
{
	double bankBalance = 0.0;
	int count = 0;
	int selection = 0;
	int recSelection = 0;
	int newCust = 0;
	bool done = false;
	bool recDone = false;

	SavingsAccount accountOne(7000.00,0.0025,"005523457","1337",12);

	do
	{
		welcome();
		menuNew();
		cin >> selection;
		switch (selection)
		{
			case 1:
			{
				system("cls");
				welcome();

				double startBalance = 0.0;
				double startInterestRate = 0.0025;
				string newAccountNumber = "005524858";
				string newCustomerID = "2277";
				int newFreq = 12;

				cout << "Please enter your starting balance: ";
				cin >> startBalance;

				SavingsAccount accountTwo(startBalance, startInterestRate, newAccountNumber, newCustomerID, newFreq);

				done = true;
				break;
			}

			case 2:
			{
				do
				{
					system("cls");
					welcome();
					menuRec();
					cin >> recSelection;

					switch (recSelection)
					{
						case 1:
						{
							system("cls");
							welcome();
							menuDeposit(accountOne);
							break;
						}

						case 2:
						{
							system("cls");
							welcome();
							menuWithdraw(accountOne);
							break;
						}

						case 3:
						{
							system("cls");
							welcome();
							cout << "\n\nThank You! " << endl;
							system("pause");
							done = true;
							recDone = true;
							break;
						}

						default:
						{
							cout << endl << endl;
							cout << "Please enter a valid selection..." << endl;
							system("pause");
							system("cls");
							break;
						}
					}
				} while (!recDone);
				break;
			}

			default:
			{
				cout << endl << endl;
				cout << "Please enter a valid selection..." << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	} while (!done);





	system("pause");
	return 0;
}

void welcome()
{
	cout << "Welcome to BankPro 1.0" << endl << endl;
}

void menuRec()
{
	cout << "Please make a selection from the following menu: " << endl;
	cout << "1. Make a Deposit" << endl;
	cout << "2. Make a Withdrawal" << endl;
	cout << "3. Exit" << endl;
	cout << "Selection: ";
}

void menuNew()
{
	cout << "Are you a returning customer or a new one? " << endl;
	cout << "1. New" << endl;
	cout << "2. Returning" << endl;
	cout << "Selection: ";
}

void menuDeposit(SavingsAccount& activeAcc)
{
	double deposit = 0.0;
	cout << fixed << setprecision(2);
	cout << "Your current balance: $" << activeAcc.getBalance() << endl << endl;
	cout << "Please enter the amount you wish to deposit: $";
	cin >> deposit;

	activeAcc.deposit(deposit);

	cout << endl << endl << "Your new balance: $" << activeAcc.getBalance() << endl;
	system("pause");
	system("cls");
}

void menuWithdraw(SavingsAccount& activeAcc)
{
	double withdraw = 0.0;
	cout << fixed << setprecision(2);
	cout << "Your current balance: $" << activeAcc.getBalance() << endl << endl;
	cout << "Please enter the amount you wish to withdraw: $";
	cin >> withdraw;

	activeAcc.withdraw(withdraw);

	cout << endl << endl << "Your new balance: $" << activeAcc.getBalance() << endl;
	system("pause");
	system("cls");
}