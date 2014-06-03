/*File Name: SavingsAccount.h
Programmer: Joesph Olliff
Purpose: The Savings Account object used in the Bank Account Manager */

#include <iostream>
#include <string>

using namespace std;

class SavingsAccount
{
	private:
		double balance;
		double interestRate;
		string accountNumber;
		string customerID;
		int compoundFreq;

	public:
		SavingsAccount(double,double,string,string,int);
		double getBalance();
		double getInterestRate();
		string getAccountNumber();
		string getCustomerID();
		int getCompoundFreq();
		void deposit(double);
		void withdraw(double);
		void setInterestRate(double);
};

SavingsAccount::SavingsAccount(double startBalance, double startRate, string acctNum, string customer, int startFreq)
{
	balance = startBalance;
	interestRate = startRate;
	accountNumber = acctNum;
	customerID = customer;
	compoundFreq = startFreq;
}

double SavingsAccount::getBalance()
{
	return balance;
}

double SavingsAccount::getInterestRate()
{
	return interestRate;
}

string SavingsAccount::getAccountNumber()
{
	return accountNumber;
}

string SavingsAccount::getCustomerID()
{
	return customerID;
}

int SavingsAccount::getCompoundFreq()
{
	return compoundFreq;
}

void SavingsAccount::deposit(double amtToDeposit)
{
	balance += amtToDeposit;
}

void SavingsAccount::withdraw(double amtToWithdraw)
{
	balance -= amtToWithdraw;
}

void SavingsAccount::setInterestRate(double newInterestRate)
{
	interestRate = newInterestRate;
}