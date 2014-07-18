/*File Name: AgesMain.cpp
Programmer: Joesph Olliff
Purpose: Controller program use to read data from a file and perform statistical operations with said data*/

#include <iostream>
#include <string>
#include "ListOfAges.h"
using namespace std;

int main()
{
	string file = "";
	double average = 0.0;
	int below = 0;
	double stdDev = 0.0;

	cout << "Please enter the file name: ";
	cin >> file;

	ListOfAges age(file);

	age.loadAges();

	cout << "List of Ages from file: " << file << "\n\n";

	age.displayAges();

	cout << "\n\n";

	average = age.calcAverageAge();
	below = age.countBelowAverage();
	stdDev = age.calcStandardDeviation();

	cout << "The average age: " << average << "  The number of ages below average: " << 
		below << "\nThe Standard Deviation of the set: " << stdDev << endl;

	system("pause");
	return 0;
}