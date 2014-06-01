//FILE : NQLPMain.cpp
//PROG : Joesph Olliff
//PURP : To calculate expendatures of a series of NQL Plants

#include <fstream>
#include <istream>
#include <iomanip>
#include <array>
#include <map>
#include <iostream>
#include <string>

using namespace std;

const int NUM_PLANTS = 3; //Static number of Plants (must change when adding Plants!)
const int NUM_PROD = 3; //Static number of Products (must change when adding Products!)
const int NUM_COMP = 5; //Static number of Components (Due to intrensic nature of the components and there use, leave this unchanged)

int numEntry(ifstream& file) //Determines the number of plants in the file (Used for double verification of price seperation)
{
	string s;
	int entry = 0;
	while (getline(file, s))
	{
		entry++;
		if (s.empty())
		{
			break;
		}
	}
	return entry;
}

ifstream& GotoLine(ifstream& file, unsigned int num) //Sets the file reader to the desired position
{
	file.seekg(ios::beg);
	for (int i = 0; i < num - 1; ++i){
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

void getProd(ifstream& file, int plants[][NUM_PROD]) //Get the number of products produced from each plant
{
	int count = 0;
	int count2 = 0;
	int temp = 0;
	while (!file.eof())
	{
		file >> temp;
		if (count >= NUM_PLANTS)
		{
			break;
		}

		plants[count][count2] = temp;
		count2++;
		if (count2 >= NUM_PROD)
		{
			count2 = 0;
			count++;
		}
	}
}

void getPrice(ifstream& file, int prices[], int entry) //Get the individual component prices
{
	int temp = 0;
	int count = 0;
	GotoLine(file, entry);

	while (!file.eof())
	{
		file >> temp;
		prices[count] = temp;
		count++;
	}
}

void initComp(int comp[][NUM_PROD]) //Initialize Components
{
	int count = 0;
	int count2 = 0;

	for (count = 0; count < NUM_COMP; count++)
	{
		for (count2 = 0; count2 < NUM_PROD; count2++)
		{
			switch (count)
			{
				case 0:
					switch (count2)
					{
						case 0:
							comp[count][count2] = 1;
							break;

						case 1:
							comp[count][count2] = 1;
							break;

						case 2:
							comp[count][count2] = 1;
							break;
					}
					break;

				case 1:
					switch (count2)
					{
						case 0:
							comp[count][count2] = 3;
							break;

						case 1:
							comp[count][count2] = 3;
							break;

						case 2:
							comp[count][count2] = 12;
							break;
					}
					break;

				case 2:
					switch (count2)
					{
						case 0:
							comp[count][count2] = 3;
							break;

						case 1:
							comp[count][count2] = 2;
							break;

						case 2:
							comp[count][count2] = 2;
							break;
					}
					break;

				case 3:
					switch (count2)
					{
						case 0:
							comp[count][count2] = 0;
							break;

						case 1:
							comp[count][count2] = 2;
							break;

						case 2:
							comp[count][count2] = 8;
							break;
					}
					break;

				case 4:
					switch (count2)
					{
						case 0:
							comp[count][count2] = 3;
							break;

						case 1:
							comp[count][count2] = 2;
							break;

						case 2:
							comp[count][count2] = 6;
							break;
					}
					break;
			}
		}
	}
}

void prodCost(int comp[][NUM_PROD], int costs[], int prices[]) //Calculate the cost of each product
{
	int count = 0;
	int count2 = 0;

	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;

	for (count = 0; count < NUM_COMP; count++)
	{
		for (count2 = 0; count2 < NUM_PROD; count2++)
		{
			switch (count2)
			{
				case 0:
					temp1 += comp[count][count2] * prices[count];
					break;
				case 1:
					temp2 += comp[count][count2] * prices[count];
					break;
				case 2:
					temp3 += comp[count][count2] * prices[count];
					break;
			}
		}
	}

	costs[0] = temp1;
	costs[1] = temp2;
	costs[2] = temp3;

}

void matTotal(int comp[][NUM_PROD], int matTotals[][NUM_PLANTS], int plants[][NUM_PROD]) //Calculate totals for each material needed by each Plant
{
	int count = 0;
	int count2 = 0;

	for (count = 0; count < NUM_PLANTS; count++)
	{
		for (count2 = 0; count2 < NUM_COMP; count2++)
		{
			matTotals[count2][count] = (comp[count2][0] * plants[count][0]) + (comp[count2][1] * plants[count][1]) + (comp[count2][2] * plants[count][2]);//Headache formulating formulae
		}
	}
}

void matCost(int prices[], int matCost[], int matTotals[][NUM_PLANTS]) //Calculate total Materials cost for each Plant
{
	int count = 0;
	int count2 = 0;

	for (count = 0; count < NUM_PLANTS; count++)
	{
		matCost[count] = 0;
	}

	for (count = 0; count < NUM_PLANTS; count++)
	{
		for (count2 = 0; count2 < NUM_COMP; count2++)
		{
			matCost[count] += matTotals[count2][count] * prices[count2];
		}
	}

}

void dispProdCost(int costs[])
{
	system("cls");
	cout << "PRODUCT COSTS TABLE" << endl;
	cout << "Notepad Holder:    " << costs[0] << endl;
	cout << "Letter Holder:     " << costs[1] << endl;
	cout << "Pen Holder:        " << costs[2] << endl << endl;

	system("pause");
	system("cls");
}

void dispMatReq(int matTotals[][NUM_PLANTS])
{
	int count = 0;

	system("cls");
	cout << "MATERIALS REQUIREMENTS TABLE" << endl;
	cout << setw(24) << "Base" << setw(12) << "Leather" << setw(12) << "Hoop" << setw(12) << "Extens" << setw(12) << "Labor" << endl;
	cout << "Plant 1:    ";
	for (count = 0; count < NUM_COMP; count++)
	{
		cout << setw(12) << matTotals[count][0];
	}
	cout << endl;

	cout << "Plant 2:    ";
	for (count = 0; count < NUM_COMP; count++)
	{
		cout << setw(12) << matTotals[count][1];
	}
	cout << endl;

	cout << "Plant 3:    ";
	for (count = 0; count < NUM_COMP; count++)
	{
		cout << setw(12) << matTotals[count][2];
	}
	cout << endl << endl;

	system("pause");
	system("cls");
}

void dispProjCost(int matCost[])
{
	system("cls");
	cout << "MATERIAL COSTS TABLE" << endl;
	cout << "Plant 1:    " << matCost[0] << endl;
	cout << "Plant 2:    " << matCost[1] << endl;
	cout << "Plant 3:    " << matCost[2] << endl << endl;

	system("pause");
	system("cls");
}

int main()
{
	//File reading object
	ifstream fileRead;

	//Storage and calculation arrays
	int plants[NUM_PLANTS][NUM_PROD];
	int components[NUM_COMP][NUM_PROD];
	int costsProd[NUM_PROD];
	int matTotals[NUM_COMP][NUM_PLANTS];
	int matCosts[NUM_PLANTS];
	int prices[NUM_COMP];


	//storage tools
	string fileName;
	int count = 0;
	int count2 = 0;
	int plaNum = 0; //used in setting the pointer in the file (leave unchanged when adding additional Plants)

	//Menu Tools
	int choice = 0;
	bool done = false;
	
	cout << "Please enter the name of the file (case sensitive, include file extension): "; //Get File name
	getline(cin, fileName); 

	if (fileName.empty()) //Verify that the user entered something
	{
		system("cls");
		cout << "Error no File Name entered... exiting... " << endl;
		system("pause");
	}
	else
	{
		fileRead.open(fileName);
		if (fileRead.is_open()) //Check that the file was found and opened
		{
			plaNum = numEntry(fileRead); //Find the blank line indicating the end of plant info
			fileRead.close();

			fileRead.open(fileName); // close and reopen the file to reset the pointer
			getProd(fileRead, plants);
			getPrice(fileRead, prices, plaNum);
			initComp(components);
			prodCost(components, costsProd, prices);
			matTotal(components, matTotals, plants);
			matCost(prices, matCosts, matTotals);

			fileRead.close();

			while (!done)
			{
				system("cls");
				cout << "Please choose an option: " << endl;
				cout << "1. Display Product Costs " << endl;
				cout << "2. Material Requirements for each Plant " << endl;
				cout << "3. Projected Material Costs " << endl;
				cout << "4. Exit " << endl << endl;
				cout << "Enter Choice: " << endl;
				cin >> choice;

				switch (choice)
				{
					case 1:
						dispProdCost(costsProd);
						break;

					case 2:
						dispMatReq(matTotals);
						break;

					case 3:
						dispProjCost(matCosts);
						break;

					case 4:
						done = true;
						break;

					default:
						system("cls");
						cout << "Error invalid entry, please try again..." << endl;
						system("pause");
						break;
				}

				
			}
			//begin debug area
			

			//end debug area
		}
		else
		{
			system("cls");
			cout << "Error File not found... exiting... " << endl;
			system("pause");
		}
	}
	return 0;
}





