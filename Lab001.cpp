// Niloufar Shamloo
// Lab 01

#include "stdafx.h"
#include <iostream>
#include <fstream>
using std::ifstream;
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string filename;
	ifstream inFile;
	double first(0),
		second(0),
		last(0),
		last1(0),
		temporary(0);
	int count(0);
	cout << "Enter the filename: \n"; // we ask the user for the file name which as to be entered using the complete directory address.
	cin >> filename; // input the filaname
	inFile.open(filename); // open the file
	if (inFile.is_open()) // if the file is open
	{
		while (!inFile.eof()) // while it is not the end of file
		{
			inFile >> temporary; // store the values of influe in temporary 
			if (!inFile.fail()) // control the read process using the .fail() stream method
			{
				if (count == 0) // if the count is equal to zero, we have the first number
				{
					first = temporary; // we store the temporary in first
				}
				if (count == 1) // if the count is equal to one, we have the second number
				{
					second = temporary; // what is in temp at that point, will be assigned to second.
				}
				last1 = last; //at this point, whatever is in the last, will be asisgned to second to last.
				last = temporary; // what is in the temporary, will be the last value
				count++; // we increment the count as we go
			}
			else
			{
				inFile.clear(); // all the numbers in between need to be cleared
				inFile.ignore(); // and ignored
			}
		}
	}
	inFile.close(); // close the file 
	cout << "The first number is: " << first << endl; // print the results
	cout << "The second number is: " << second << endl; // print the results
	cout << "The second to last number is: " << last1 << endl; // print the results
	cout << "The last number is: " << last << endl; // print the results
	cout << "The count is: " << count << endl; // print the count
	return 0;
}
