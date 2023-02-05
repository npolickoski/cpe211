// ****************************************
// Program Title: Sample header file
// Project File: Project_05.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 1 
// Due Date: 09/25/2022 
// Program Description: 
// ****************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[ ])
{
	//// Test for if input file name was provided
	if (argc != 2) 
	{ 
		cout << endl; 
		cout << string(9,'*') << " Command Line Argument Error "  
			 << string(9,'*') << endl; 
		cout << "==> Incorrect number of Command Line Arguments!\n"; 
		cout << "==> Command for running the program is:\n"; 
		cout << "==> ./Project_05 inputFileName\n"; 
		cout << string(47,'*') << endl << endl;

		return 1; 
	}

	//// Declaring Filestream/Filename Variables and Opening the File
	ifstream fin; //file input stream
	string filename = argv[1]; //file to be inputted

	fin.open(filename.c_str()); // assigns file stream to the inputted file

	// Header
	cout << endl << string(60, '*') << endl
	     << string(20, '*') << "  Triangle Checker  "
		 << string(20, '*') << endl 
		 << string(60, '*') << endl << endl;

	// Confirmation of Running File
	cout << "Opening input file: " << filename << endl << endl;



	// Testing Filestream State
	if(!(fin)) 
	{ 
		cout << string(15,'*') << " File Open Error "  
			 << string(15,'*') << endl; 
		cout << "==> Input file failed to open properly!!\n"; 
		cout << "==> Attempted to open file: " << filename << endl; 
		cout << "==> Terminating program!!!\n"; 
		cout << string(47,'*') << endl << endl;

		return 1; 
	}

	// Initializing Variables
	char u; //test variable

	double a, b, c; //sides of triangle
	string guess; //triangle type guess

	//// Extracting Data from Input Files	 
	cout << "Reading Values From Input File..." << endl << endl;

	for (int i = 0; i < 4; i++) //for every new line in the file, 
	{
		fin >> u;

		// Testing if Input File is Empty
		if (fin.eof())
		{
			cout << string(13,'*') << " Input File Is Empty "  
				 << string(13,'*') << endl; 
			cout << "==> No Information in the input file.\n"; 
			cout << "==> Terminating program now...\n"; 
			cout << string(47,'*') << endl << endl;

			return 1;
		}

		if (u == 'a')
			fin >> a;

		if (u == 'b')
			fin >> b;

		if (u == 'c')
			fin >> c;
		
		if (u == '?')
			fin >> guess;

	}
			
			
	//// Testing Filestream Again
	if(fin.fail()) 
	{ 
		cout << string(15,'*') << " File Read Error "  
			 << string(15,'*') << endl; 
		cout << "==> Error reading data from input file.\n";  
		cout << "==> Terminating program now...\n"; 
		cout << string(47,'*') << endl << endl;

		return 1; 
	}
		
	// Test for Data Validity
	if (!((a > 0) && (b > 0) && (c > 0)))
	{
		cout << string(15,'*') << " File Data Error "  
			 << string(15,'*') << endl; 
		cout << "==> Error: One or more side lengths are negative.\n";  
		cout << "==> Terminating program now...\n"; 
		cout << string(47,'*') << endl << endl;

		return 1;
	}

	// Value Output
	cout << "Summary of Data Read..." << endl
		 << "Side A = " << fixed << setprecision(2) << a << endl
		 << "Side B = " << b << endl
		 << "Side C = " << c << endl
		 << "Guess  = " << guess << endl;
	cout << string(60, '*') << endl;


	// Determinng If Values Make Trianlge and Type of Triangle
	string triType;
	bool isTriangle;

	if ((a < b + c) && (b < a + c) && (c < a + b))
	{
		isTriangle = true;

		if ((a == b) && (b == c) && (a == c))
			triType = "equilateral";
		
		else if ((a == b) || (a == c) || (b == c))
			triType = "isosceles";

		else
			triType = "scalene"; 
	}
	else
	{
		isTriangle = false;
		triType = "not-triangle";
	}


	// Area and Perimeter Calculations
	double P, s, A; //area, perimeter, half-perimeter respectively

	P = (a + b + c); // perimeter formula
	s = P / 2.0; // half-perimeter formula
	A = pow((s * (s-a) * (s-b) * (s-c)), 0.5); //area of a triangle formula (Heron's)
	

	// Result Output
	cout << "Results From Data Read:" << endl;
	cout << left << setfill('.'); 
	cout << setw(13) << "Type" << fixed << setprecision(2) << triType << endl;

	if (isTriangle == true)
	{
		cout << setw(13) << "Area" << fixed << setprecision(2) << A << endl
			<< setw(13) << "Perimeter" << fixed << setprecision(2) << P << endl;
	}

	if (guess == triType)
		cout << endl << "Congratulations!  Triangle specified is correct" << endl;
	else
		cout << endl << "Sorry! Triangle specified is incorrect" << endl;


	cout << string(60, '*') << endl << endl;

	return 0;
}
