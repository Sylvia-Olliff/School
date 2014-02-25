//FILE : Process Home Construction Data.cpp
//PROG : Joesph Olliff
//PURP : To read and process data from the homefee.dat file

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;

//Function prototypes here
string transType(char trans) //translate Item Codes
{
	string translation = "";
	switch (toupper(trans))
	{
		case 'M':
			translation = "MATLS";
			break;

		case 'L':
			translation = "LABOR";
			break;

		case 'I':
			translation = "INSPC";
			break;

		case 'C':
			translation = "CONTR";
			break;

		case 'E':
			translation = "ELECT";
			break;

		default:
			translation = "ERROR";
			break;
	}

	return translation;
}

double laborCalc(int hours, double charge) //Calculate hourly rate
{
	double result = 0.0;
	
	result = charge / static_cast<double>(hours);
	return result;
}

//Display a single entry from the file in the order in which it was read
void dispSing(string name, string code, string type, double hour, double charge, int entry) 
{
	cout.imbue(locale(""));

	hour *= 100;
	charge *= 100;

	cout << "\n\n" << setprecision(2) << fixed;
	cout << setw(2) << "#" << setw(14) << "CONTR CODE" << setw(14) << "ITEM NAME" << setw(10) << "TYPE" << setw(14) << "COST/HOUR" << setw(14) << "ITEM COST" << endl;
	cout << setw(2) << entry << setw(14) << code << setw(14) << name << setw(10) << type << setw(14);
	if (static_cast<int>(hour) > 0) { cout << put_money(hour) << setw(14) << put_money(charge) << endl << endl; }
	else { cout << " " << setw(14) << showbase << put_money(charge) << endl << endl; }
	system("pause");
}

//Display the full report, properly formated and sorted based off of type
void dispFull(string name[], string code[], string type[], double hour[], double charge[], int entry, double greatest, int days[])
{
	int count = 0;
	int count2 = entry;
	int sort = 0;
	int sort2 = 0;
	int sequential = 0;
	string temp1[100], temp2[100], temp3[100];
	double temp4[100], temp5[100];
	int temp6[100];
	cout.imbue(locale(""));
	entry = 0;

	for (count = 0; count < 100; count++) //initialize
	{
		temp1[count] = "";
		temp2[count] = "";
		temp3[count] = "";
		temp4[count] = 0.0;
		temp5[count] = 0.0;
		temp6[count] = 0;
	}
	for (count = 0; count < 5; count++) //structured sort
	{
		for (sort = 0; sort <= count2; sort++)
		{
			switch (sequential)
			{
			case 0:
				if (type[sort].compare("CONTR") == 0)
				{
					temp1[sort2] = name[sort];
					temp2[sort2] = code[sort];
					temp3[sort2] = type[sort];
					temp4[sort2] = hour[sort];
					temp5[sort2] = charge[sort];
					temp6[sort2] = days[sort];
					sort2++;
				}
				break;

			case 1:
				if (type[sort].compare("ELECT") == 0)
				{
					temp1[sort2] = name[sort];
					temp2[sort2] = code[sort];
					temp3[sort2] = type[sort];
					temp4[sort2] = hour[sort];
					temp5[sort2] = charge[sort];
					temp6[sort2] = days[sort];
					sort2++;
				}
				break;

			case 2:
				if (type[sort].compare("INSPC") == 0)
				{
					temp1[sort2] = name[sort];
					temp2[sort2] = code[sort];
					temp3[sort2] = type[sort];
					temp4[sort2] = hour[sort];
					temp5[sort2] = charge[sort];
					temp6[sort2] = days[sort];
					sort2++;
				}
				break;

			case 3:
				if (type[sort].compare("LABOR") == 0)
				{
					temp1[sort2] = name[sort];
					temp2[sort2] = code[sort];
					temp3[sort2] = type[sort];
					temp4[sort2] = hour[sort];
					temp5[sort2] = charge[sort];
					temp6[sort2] = days[sort];
					sort2++;
				}
				break;

			case 4:
				if (type[sort].compare("MATLS") == 0)
				{
					temp1[sort2] = name[sort];
					temp2[sort2] = code[sort];
					temp3[sort2] = type[sort];
					temp4[sort2] = hour[sort];
					temp5[sort2] = charge[sort];
					temp6[sort2] = days[sort];
					sort2++;
				}
				break;
			}
		}
		sequential++;
	}

	//Full formated display using put_money
	cout << "\n\n" << setprecision(2) << fixed;
	cout << setw(2) << "#" << setw(14) << "CONTR CODE" << setw(14) << "ITEM NAME" << setw(10) << "TYPE" << setw(14) << "COST/HOUR" << setw(14) << "ITEM COST" << endl;
	for (count = 0; count < count2; count++)
	{
		entry++;
		temp4[count] *= 100; //needed for the use of put_money
		temp5[count] *= 100;
		cout << setw(2) << entry << setw(14) << temp2[count] << setw(14) << temp1[count] << setw(10) << temp3[count] << setw(14);
		if (static_cast<int>(temp4[count]) > 0) { cout << put_money(temp4[count]) << setw(14) << put_money(temp5[count]) << endl; }
		else { cout << " " << setw(14) << showbase << put_money(temp5[count]) << endl; }
	}
	cout << endl << endl << endl;
	greatest *= 100;
	//Make sure the correct "greatest" displays after having been moved in the sorting
	for (count = 0; count < count2; count++) 
	{
		if (static_cast<int>(greatest) == static_cast<int>(temp5[count]))
		{
			cout << "The greatest Expense was: " << temp1[count] << " Code: " << temp2[count] << endl << " Total Cost: " << put_money(temp5[count]) << " Completed on day: " << temp6[count] << endl;
		}
	}
	system("pause");
}

//Determine the greatest single expense
double greatest(double charge[], int entry)
{
	double great = 0.0;
	int count = 0;

	for (count = 0; count < entry; count++)
	{
		if (static_cast<int>(great) < static_cast<int>(charge[count]))
		{
			great = charge[count];
		}
	}
	return great;
}

//Extra credit function. Self contained process for determining the total expenses for each expense type
void sectionCharges()
{
	//File input reader
	ifstream dataIn;

	//Entry data points
	string itemName, itemCode;
	char itemType;
	int hours, day;
	double charge;

	//Accumulation variables and tools
	string type;
	double chargMat = 0.0;
	double chargIns = 0.0;
	double chargEle = 0.0;
	double chargLab = 0.0;
	double chargCon = 0.0;
	cout.imbue(locale(""));

	dataIn.open("homefees.dat");
	if (dataIn.is_open()) // Verify file was opened
	{
		while (!dataIn.eof()) //Continue to read until the end of file is reached
		{
			dataIn >> itemName
				>> itemCode
				>> itemType
				>> hours
				>> charge
				>> day;

			type = transType(itemType);
			if (type.compare("LABOR") == 0)
			{
				chargLab += charge;
			}
			else if (type.compare("ELECT") == 0)
			{
				chargEle += charge;
			}
			else if (type.compare("INSPC") == 0)
			{
				chargIns += charge;
			}
			else if (type.compare("MATLS") == 0)
			{
				chargMat += charge;
			}
			else if (type.compare("CONTR") == 0)
			{
				chargCon += charge;
			}
		}
		chargCon *= 100;
		chargLab *= 100;
		chargEle *= 100;
		chargIns *= 100;
		chargMat *= 100;
		cout << "\n\n";
		cout << "Totals by Type:" << endl;
		cout << "Labor: " << setw(25) << put_money(chargLab) << endl;
		cout << "Materials: " << setw(21) << put_money(chargMat) << endl;
		cout << "Inspections: " << setw(16) << put_money(chargIns) << endl;
		cout << "Contractors: " << setw(16) << put_money(chargCon) << endl;
		cout << "Electrical: " << setw(17) << put_money(chargEle) << endl;
	}
	else
	{
		cout << "ERROR! CAN\'T OPEN FILE! " << endl;
		system("pause");
	}
	dataIn.close();
}

void banner()
{
	cout << "*********************************************************************" << endl;
	cout << "**       THANK YOU FOR USING HOME CONSTRUCTION COST CALC           **" << endl;
	cout << "**     MADE BY: Joesph Olliff     LAST REVISION: 2-24-2014         **" << endl;
	cout << "*********************************************************************" << endl;
}

int main()
{
	//Input file stream object to read the data file
	ifstream homedataIn;

	//Variables for the incoming fields
	string itemName, itemCode;
	char itemType;
	int hours, day;
	double charge;

	//Entry Storage Variables
	string name[100], code[100], type[100];
	double hourRate[100], totalCharge[100];
	int days[100];
	double greatChar = 0.0;
	
	//Tools
	int count = 0;
	int entryCount = 0;

	//Initialize Arrays
	for (count = 0; count < 100; count++)
	{
		name[count] = "";
		code[count] = "";
		type[count] = "";
		hourRate[count] = 0.0;
		totalCharge[count] = 0.0;
		days[count] = 0;
	}
	

	//Open the data file
	homedataIn.open("homefees.dat");
	if (homedataIn.is_open())
	{
		banner();
		//Begin the central record-processing while loop
		count = 0;
		while (!homedataIn.eof())
		{
			//Read the next record (bottom of while loop)
			homedataIn >> itemName
				>> itemCode
				>> itemType
				>> hours
				>> charge
				>> day;
			name[count] = itemName;
			code[count] = itemCode;
			type[count] = transType(itemType);
			if (hours > 0)
			{
				hourRate[count] = laborCalc(hours, charge);
			}
			totalCharge[count] = charge;
			days[count] = day;
			entryCount++;

			dispSing(name[count], code[count], type[count], hourRate[count], totalCharge[count], entryCount);
			system("cls");
			banner();
			count++;
		}//END OF RECORD PROCESSING WHILE LOOP

		//Close the data file since we are done with it
		homedataIn.close();
		greatChar = greatest(totalCharge, entryCount);
		dispFull(name, code, type, hourRate, totalCharge, entryCount, greatChar, days);
		system("cls");
		banner();
		sectionCharges();

	}//END IF FILE OPENED
	else  //File did not open
		cout << "The sales file did not open!\n";

	cout << "\n\n";
	system("pause");
	return 0;
}//END MAIN