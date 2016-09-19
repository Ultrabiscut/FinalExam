#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Program: FinalExam
//Author: Tyler Timmins
//Class: ITSE 1307 2002
//Description: Write a progaram that takes a list of tempatures and converts them
// to fahrenheit, finds the average, hottest, and coolest of them and display all.


int main()
{
	//delcare variables
	ifstream inputFile;
	double dTemps[31]; //hold tempatures
	double dConvertedTemps[31]; //hold converted temps (used only for average)
	double dHottest = INT_MIN; //calculate hottest temp
	int iHottestLoc; // store palce of hottest
	double dCoolest = INT_MAX; //calculate lowest temp
	int iCoolestLoc; //store place of lowest
	double dFahrenheit; //conversion holder
	double dSum = 0, dAverageTemp; // used to find average
	int iCounter = 0; //used to count each tempature

	//open file temps.txt
	inputFile.open("temps.txt");

	//loop 31 times, each time read a tempature
	//convert it and store into array dTemps[]
	for (int x = 0; x <= 30; x++)
	{
		inputFile >> dTemps[x]; //read a tempature store into array
		
		iCounter++; //count each tempature 

		//find hottest high temp
		//and display that number
		if (dTemps[x] > dHottest)
		{
			dHottest = dTemps[x]; //stores biggest temp
			iHottestLoc = x; //store the index was found at

			//convert to fahrenheit
			dHottest = ((dTemps[x] * 9) / 5) + 32;
		}
		
		//find coolest temp
		//and display that number
		if (dTemps[x] < dCoolest)
		{
			dCoolest = dTemps[x]; // stores the coolest temp
			iCoolestLoc = x; //store the index was found at

			//convert to fahrenheit
			dCoolest = ((dTemps[x] * 9) / 5) + 32;
		}
	}
	//close the file
	inputFile.close();
	

	//find the average temp
	//and display that temp
	for (int x = 0; x <= 30; x++)
	{
		//convert to fahrenheit
		dTemps[x] = ((dTemps[x] * 9.0) / 5.0) + 32.0;

		//find the average
		dSum = dSum + dTemps[x];
	}

	//Finish the average
	dAverageTemp = dSum / iCounter;
	
	//set precision to a fixed decimal spot


	//output
	cout << "MARCH 2015 TEMPERATURES" << endl;
	cout << endl;
	cout << "Average High Temp: " << dAverageTemp << endl << endl;
	cout << "Hottest High Temp: " << dHottest << " on March " << iHottestLoc << endl << endl;
	cout << "Coolest High Temp: " << dCoolest << " on March " << iCoolestLoc << endl << endl;

	return 0;
}