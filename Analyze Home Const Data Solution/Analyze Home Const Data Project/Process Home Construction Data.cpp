//FILE : Process Home Construction Data.cpp
//PROG : Joesph Olliff
//PURP : To read and process data from the homefee.dat file

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <direct.h>

using namespace std;
const int SIZE = 1000;
int entryCount = 0;
int numValid = 0;

struct list
{
	string name, code, type;
	double laborCost, totalCharge;
	int day;
	bool isValid = true;
	char typeCode = ' ';
}entry;

list entries[SIZE];
list entriesTemp;
list entriesAnnoy[SIZE];

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
			translation = "UNKNW";
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

void readInitial() // Initial reading of homefees-b
{
	ifstream homedataIn;

	int count = 0;
	string itemName, itemCode;
	char itemType;
	int hours, day;
	double charge;

	homedataIn.open("homefees-b.dat");
	if (homedataIn.is_open())
	{
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
			entries[count].name = itemName;
			entries[count].code = itemCode;
			entries[count].type = transType(itemType);
			entries[count].typeCode = itemType;
			if (entries[count].type.compare("UNKNW"))
			{
				entries[count].isValid = false;
			}
			if (hours > 0)
			{
				entries[count].laborCost = laborCalc(hours, charge);
			}
			entries[count].totalCharge = charge;
			entries[count].day = day;
			entryCount++;
			count++;
		}//END OF RECORD PROCESSING WHILE LOOP

		//Close the data file since we are done with it
		homedataIn.close();
	}
	else
	{
		cout << "Error opening file... aborting..." << endl;
		system("pause");
	}
}

void generateValidNum()
{
	int count = 0;

	for (count = 0; count < entryCount; count++)
	{
		if (entries[count].isValid)
		{
			numValid++;
		}
	}
}

void sortDay()
{
	//tools
	int sub = 0;
	int maxSub = entryCount - 1;
	int lastSwap = 0;
	bool swap = true;

	//storing the sort
	ofstream sorted;

	//Bubble sort
	while (swap)
	{
		swap = false;

		sub = 0;

		while (sub < maxSub)
		{
			if (entries[sub].day > entries[sub + 1].day)
			{
				entriesTemp.day = entries[sub].day;
				entriesTemp.code = entries[sub].code;
				entriesTemp.name = entries[sub].name;
				entriesTemp.type = entries[sub].type;
				entriesTemp.isValid = entries[sub].isValid;
				entriesTemp.laborCost = entries[sub].laborCost;
				entriesTemp.totalCharge = entries[sub].totalCharge;
				entriesTemp.typeCode = entries[sub].typeCode;

				entries[sub].day = entries[sub + 1].day;
				entries[sub].code = entries[sub + 1].code;
				entries[sub].name = entries[sub + 1].name;
				entries[sub].type = entries[sub + 1].type;
				entries[sub].isValid = entries[sub + 1].isValid;
				entries[sub].laborCost = entries[sub + 1].laborCost;
				entries[sub].totalCharge = entries[sub + 1].totalCharge;
				entries[sub].typeCode = entries[sub + 1].typeCode;

				entries[sub + 1].day = entriesTemp.day;
				entries[sub + 1].code = entriesTemp.code;
				entries[sub + 1].name = entriesTemp.name;
				entries[sub + 1].type = entriesTemp.type;
				entries[sub + 1].isValid = entriesTemp.isValid;
				entries[sub + 1].laborCost = entriesTemp.laborCost;
				entries[sub + 1].totalCharge = entriesTemp.totalCharge;
				entries[sub + 1].typeCode = entriesTemp.typeCode;

				swap = true;
				lastSwap = sub;
			}
			sub++;
		}
		maxSub = lastSwap;
	}

	sorted.open("Sorted.dat", ios::out);

	if (sorted.is_open())
	{
		for (int count = 0; count < entryCount; count++)
		{
			sorted << entries[count].day << " " << entries[count].name << " " << entries[count].code << " "
				<< entries[count].typeCode << " " << entries[count].laborCost << " " << entries[count].totalCharge << " "
				<< endl;
		}
	}
	else
	{
		cout << "Error creating file \"Sorted.dat\"" << endl;
	}

	sorted.close();
}

void createAnnoying()
{
	ofstream annoy;

	int count = 0;
	int tracker = 0;

	for (count = 0; count < entryCount; count++)
	{
		if (!entries[count].isValid)
		{
			entriesAnnoy[count].day = entries[count].day;
			entriesAnnoy[count].code = entries[count].code;
			entriesAnnoy[count].isValid = entries[count].isValid;
			entriesAnnoy[count].laborCost = entries[count].laborCost;
			entriesAnnoy[count].name = entries[count].name;
			entriesAnnoy[count].totalCharge = entries[count].totalCharge;
			entriesAnnoy[count].type = entries[count].type;
			entriesAnnoy[count].typeCode = entries[count].typeCode;

			tracker++;
		}
	}

	annoy.open("Annoying Programmer.dat", ios::out);

	if (annoy.is_open())
	{
		annoy << entryCount - numValid << endl;

		//input invalid entries sorted by day
		for (count = 0; count < tracker; count++)
		{
			if (!entriesAnnoy[count].isValid)
			{
				annoy << entriesAnnoy[count].day << " " << entriesAnnoy[count].code << " " << entriesAnnoy[count].name << " " << entriesAnnoy[count].typeCode
					<< " " << entriesAnnoy[count].laborCost << " " << entriesAnnoy[count].totalCharge << endl;
			}
		}
		annoy << numValid << endl;

		//input valid entries sorted by day
		for (count = 0; count < entryCount; count++)
		{
			if (entries[count].isValid)
			{
				annoy << entries[count].day << " " << entries[count].code << " " << entries[count].name << " " << entries[count].typeCode
					<< " " << entries[count].laborCost << " " << entries[count].totalCharge << endl;
			}
		}
	}
	else
	{
		cout << "Error creating file \"Annoying Programmer.dat\"" << endl;
	}

	annoy.close();
}

void createCSV()
{
	ofstream csv;
	int count = 0;

	csv.open("SpreadEm.csv", ios::out);

	if (csv.is_open())
	{
		csv << "Day,Product,Contractor ID,Type,Hourly,Total Charge," << endl;
		for (count = 0; count < entryCount; count++)
		{
			csv << entries[count].day << "," << entries[count].name << "," << entries[count].code << ","
				<< entries[count].type << "," << entries[count].laborCost << "," << entries[count].totalCharge << "," 
				<< endl;
		}
	}
	else
	{
		cout << "Error creating file \"SpreadEm.csv\"" << endl;
	}
	csv.close();
}

void createWeekSumm()
{
	ofstream summ;

	int count = 0;
	int weekTrack = 0;
	int weekNum = 1;
	double totLab = 0.0, 
		totMat = 0.0, 
		totIns = 0.0, 
		totCon = 0.0, 
		totEle = 0.0, 
		totInv = 0.0, 
		totAll = 0.0;
	
	for (count = 0; count < entryCount; count++)
	{
		if (weekTrack < 8)
		{
			weekTrack++;
			if (toupper(entries[count].typeCode) == 'L')
			{
				totLab += entries[count].totalCharge;
			}
			else if (toupper(entries[count].typeCode) == 'M')
			{
				totMat += entries[count].totalCharge;
			}
			else if (toupper(entries[count].typeCode) == 'I')
			{
				totIns += entries[count].totalCharge;
			}
			else if (toupper(entries[count].typeCode) == 'C')
			{
				totCon += entries[count].totalCharge;
			}
			else if (toupper(entries[count].typeCode) == 'E')
			{
				totEle += entries[count].totalCharge;
			}
			else
			{
				totInv += entries[count].totalCharge;
			}

		}
		else
		{
			weekTrack = 0;
			totAll = totCon + totEle + totIns + totInv + totLab + totMat;

			summ.open("Weekly Summary.txt", ios::app);

			if (summ.is_open())
			{
				summ << "Week: " << weekNum << endl;
				weekNum++;
				summ << setprecision(2) << fixed;
				summ << setw(10) << "LABOR: " << setw(23) << totLab << endl;
				summ << setw(10) << "MATLS: " << setw(24) << totMat << endl;
				summ << setw(10) << "INSPC: " << setw(25) << totIns << endl;
				summ << setw(10) << "CONTR: " << setw(24) << totCon << endl;
				summ << setw(10) << "ELECT: " << setw(24) << totEle << endl;
				summ << setw(10) << "UNKNW: " << setw(24) << totInv << endl << endl;
				summ << setw(10) << "Total: " << setw(24) << totLab << endl << endl;
			}
			else
			{
				cout << "Error creating file \"Weekly Summary.txt\"" << endl;
			}
			summ.close();
			totAll, totCon, totEle, totIns, totInv, totLab, totMat = 0.0;
		}

	}
}

int main()
{
	_mkdir("\Output");
	
	readInitial();

	_chdir("\Output");

	generateValidNum();
	createCSV();
	sortDay();
	createWeekSumm();
	createAnnoying();

	system("pause");
	return 0;
}//END MAIN