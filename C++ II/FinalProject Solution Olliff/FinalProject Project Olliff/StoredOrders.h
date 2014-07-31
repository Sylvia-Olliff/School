/*File Name: StoredOrders.h
Programmer: Joesph Olliff
Purpose: StoredOrders Class used to describe a storage object that will be used to write all of the orders data to a file.*/

#include <iostream>
#include <fstream>

using namespace std;

class StoredOrders {
	
private:
	string file;
	bool fileOpenSuccess;
	bool append;
	ofstream o;
	ifstream f;
	bool fileExists();
	void openOutputFile();
	void closeOutputFile();
	

public:
	StoredOrders(string);
	bool getFileOpenStatus();
	void saveOneRecord(int, int, double);
	void displayAllOrders();
	double calcTotalCostOfOrders();

};