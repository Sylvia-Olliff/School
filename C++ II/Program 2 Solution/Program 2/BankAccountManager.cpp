/*File Name: BankAccountManager.cpp
  Programmer: Joesph Olliff
  Purpose: To create and alter Savings Accounts. */

#include <iostream>
#include <string>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

//prototypes
void welcome(); //Program banner
void menuRec(); //Menu for Recurring Customer
void menuNew(); //Menu for New Customer
void menuDeposit(SavingsAccount &); //Menu for making a deposit (performs the action as well)
void menuWithdraw(SavingsAccount &); //Menu for making a withdrawal (performs the action as well)
void prediction(SavingsAccount); //Simulates a period of interest accrual



int main()
{
	int selection = 0; //initial menu selection for determining if the customer is new or not
	int recSelection = 0; //menu selection for recuring customer

	//loop control variables
	bool done = false;
	bool recDone = false;

	SavingsAccount accountOne(7000.00,0.0025,"005523457","1337",12); //Account for recuring customer

	do
	{
		welcome();
		menuNew();
		cin >> selection;
		switch (selection) //Decision logic for recuring vs new customer
		{
			case 1:
			{
				system("cls");
				welcome();

				//Declare new custoemr variables here so that they only exist if needed
				double startBalance = 0.0;
				double startInterestRate = 0.0025;
				string newAccountNumber = "005524858";
				string newCustomerID = "2277";
				int newFreq = 12;

				cout << "Please enter your starting balance: $";
				cin >> startBalance;

				SavingsAccount accountTwo(startBalance, startInterestRate, newAccountNumber, newCustomerID, newFreq); //Account for new customer

				done = true;
				system("cls");
				prediction(accountTwo);
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

					switch (recSelection) //Decision logic for Deposits, Withdrawals, and finally exiting for a recuring customer
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

						case 3: //Prediction and proceding through the program only occurs once the user has selected to exit this portion
						{
							system("cls");
							welcome();
							cout << "\n\nThank You! " << endl;
							system("pause");
							done = true; 
							recDone = true;
							system("cls");
							prediction(accountOne);
							break;
						}

						default: //input error handling
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

			default: //input error handling
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

void menuDeposit(SavingsAccount &activeAcc)
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

void menuWithdraw(SavingsAccount &activeAcc)
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

void prediction(SavingsAccount activeAcc)
{
	//Prediction Display Header
	cout << fixed << setprecision(2);
	cout << "With " << activeAcc.getCompoundFreq() << " months of accrued interest with the current balance\nand no further deposits:" << endl << endl;
	cout << "Month" << setw(17) << "Starting" << setw(16) << "Interest" << setw(15) << "Ending " << endl;
	cout << "  #  " << setw(17) << "Balance " << setw(16) << " Earned " << setw(15) << "Balance" << endl << endl;

	//Display loop for a period of time determined by the Compound Frequency
	for (int count = 0; count < activeAcc.getCompoundFreq(); count++)
	{
		if (count <= 8)
		{
			cout << "  " << count+1 << "  " << setw(10) << "$" << activeAcc.getBalance() << setw(10) << "$" << (activeAcc.getBalance() * activeAcc.getInterestRate()) << setw(10)
				<< "$" << (activeAcc.getBalance() * activeAcc.getInterestRate()) + activeAcc.getBalance() << endl;
			cout << "-------------------------------------------------------------" << endl; //asthetics
			activeAcc.deposit((activeAcc.getBalance() * activeAcc.getInterestRate()) + activeAcc.getBalance());
		}
		else // I hate using setw() never seems to work right for me without wierd code like this...
		{
			cout << "  " << count+1 << "  " << setw(9) << "$" << activeAcc.getBalance() << setw(10) << "$" << (activeAcc.getBalance() * activeAcc.getInterestRate()) << setw(10)
				<< "$" << (activeAcc.getBalance() * activeAcc.getInterestRate()) + activeAcc.getBalance() << endl;
			cout << "-------------------------------------------------------------" << endl; //asthetics
			activeAcc.deposit((activeAcc.getBalance() * activeAcc.getInterestRate()) + activeAcc.getBalance());
		}
	}
}