/********************************************************************************************************
*   FILENAME: 	Exam2 Main.cpp																			*
*   PROGRAMMER: Joesph Olliff 3/25/14																	*
*   PURPOSE:	To Calculate an employee's total commission based on pay and a commission scale			*
*********************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
	//Storage Variables
	char stat = ' ';
	double totalSale = 0.0;
	double commTota = 0.0;
	double compProf = 0.0;
	double commRate = 0.0;
	
	//Static commission rates
	const double COMM_RATE_P = 0.035;
	const double COMM_RATE_FG = 0.075;
	const double COMM_RATE_FL = 0.05;

	//LCV
	bool done = false;

	//tool for money formating
	locale myLocale("");

	//verify correct input for employment status (only did this because you said that there wasn't a need for a loop ;P )
	while (!done)
	{
		cout << "Please enter your employment status (P,F): ";
		cin >> stat;

		if (toupper(stat) == 'P' || toupper(stat) == 'F')
		{
			done = true;
		}
		else
		{
			cout << endl;
			cout << "Please enter a valid entry... " << endl;
			system("Pause");
			system("cls");
		}

	}

	cout << "Please enter your total sales for this pay period: ";
	cin >> totalSale;

	if (toupper(stat) == 'P') // determine what kind of commission is to be applied
	{
		commTota = totalSale*COMM_RATE_P;
		compProf = totalSale - commTota;
		commRate = COMM_RATE_P;
	}
	else if (static_cast<int>(totalSale) < 10000)
	{
		commTota = totalSale*COMM_RATE_FL;
		compProf = totalSale - commTota;
		commRate = COMM_RATE_FL;
	}
	else
	{
		commTota = totalSale*COMM_RATE_FG;
		compProf = totalSale - commTota;
		commRate = COMM_RATE_FG;
	}

	system("cls");

	//needed to convert back to a percentage and for use of put_money()
	commTota *= 100;
	compProf *= 100;
	totalSale *= 100;
	commRate *= 100;

	stat = toupper(stat);

	//formatted display
	cout.imbue(myLocale);
	cout << setprecision(2) << fixed << showbase;
	cout << "STATUS" << setw(15) << "TOTAL SALES" << setw(14) << "RATE" << setw(15) << "COMMISSION" << setw(15) << "PROFIT" << endl;
	cout << stat << setw(19) << put_money(totalSale) << setw(15) << commRate << "%" << setw(15) << put_money(commTota) << setw(15) << put_money(compProf) << endl;

	system("pause");

	return 0;
}