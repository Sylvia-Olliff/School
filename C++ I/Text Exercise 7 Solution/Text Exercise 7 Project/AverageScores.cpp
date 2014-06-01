// FILENAME   : AverageScores.cpp
// PROGRAMMER : Joesph Olliff
// PURPOSE    : This program (once it is completed by you) will demonstrate
//              how to read records from a sequential access data file
//				The data file, scores.dat, is already located in the project directory
/*******************************************************************
* Exercise instructions:  insert appropriate C++ code where NEEDED
* to make this program compute the average of the scores
*******************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ifstream scoresIn;		//Input file stream to read the data file

	int score = 0;			//Variable used to input data from the file

	//Variables used in the processing
	int num_scores   = 0;	//counter
	int total_scores = 0;	//accumulator
	double average	= 0.0;

	//Try to open the data file.  We are assuming it is in the project directory.
	scoresIn.open ("scores.dat", ios::in);
	if (scoresIn.is_open())
	{
		//NEEDED:  Input one number from the file into the integer variable score.

		//NEEDED:  Start the while loop--while not at end of file on scoresIn
		while (!scoresIn.eof())
		{
			scoresIn >> score;
			//Then, you'll need a statement block that encloses everything down to END WHILE

			//Update counter and accumulator
			++num_scores;
			total_scores += score;
			//NEEDED:  Input another number from the file into the variable score.
		}
		//END WHILE

		//NEEDED:  close the file
		scoresIn.close();

		//Calculate and display average test score
		average = double (total_scores) / double (num_scores);
		cout << fixed << setprecision(1);
		cout << "The average test score was " << average << endl;
	} //END OF "IF THE FILE OPENED"

	else  //The file did not open
		cout << "Oops, the file did not open!  Shutting down." << endl;

	system("pause");
	return 0;
}