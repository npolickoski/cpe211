// ****************************************
// Program Title: Writing an Output File
// Project File: Project_06.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 10/04/2022 
// Program Description: takes in data from an input file,
//		uses it to create new data, and writes that data
//		to an output file.
// ****************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main(int argc, char *argv[ ])
{
    //// Declaring Variables
	// File Stream Variables
    ifstream fin;	                                               // input file stream
    ofstream fout;	                                               // output file stream
    string inFileName, outFileName;                                // names of input and output files used

	// Data Extraction Variables
	char u;												           // variable to increment character-by-character for input file 

	int countLine, countL, countD, countO, countT;                 // counts for data extracrtion (# of lines, letters, digits, symbols, and total respectively)
	countLine = countL = countD = countO = countT = 0;             // initializing count variables

	int sumL, sumD, sumO, sumT;							           // sums of all counts
	sumL = sumD = sumO = sumT = 0;                                 // initializing sum variables

	double perL, perD, perO;                                       // percentages of sums of counts


    //// Input/Output File Provided Verification
	if (argc != 3) 
	{ 
		cout << endl; 
		cout << string(9,'*') << " Command Line Argument Error "  
			 << string(9,'*') << endl; 
		cout << "==> Incorrect number of Command Line Arguments!" << endl; 
		cout << "==> Command for running the program is:" << endl; 
		cout << "==> ./Project_06 inputFileName outputFileName" << endl; 
		cout << string(47,'*') << endl << endl;

		return 1;                                                  // ends program
	}

	// Assigns Values to Argument Names
	inFileName = argv[1]; 
	outFileName = argv[2];
	

    //// Input-File Opening Verification
    cout << endl << "Opening the input file..." << endl;
    fin.open(inFileName.c_str());                                  // assigns file stream to the inputted file

    while (!(fin))
    {
        cout << endl << string(15,'*') << " File Open Error "  
			 << string(15,'*') << endl; 
		cout << "==> Input file failed to open properly!!\n"; 
		cout << "==> Attempted to open file: " << inFileName << endl; 
		cout << "==> Please try again...\n"; 
		cout << string(47,'*') << endl << endl;

		fin.clear();                                               // resets input file stream for use

		cout << "Enter in the name of the input file: ";           // new file to be inputted
		cin >> inFileName;
		cout << inFileName << endl;

		fin.open(inFileName.c_str());                              // tries new input file
    }


	//// Output-File Opening Verification
    cout << endl << "Opening the output file..." << endl << endl;
    fout.open(outFileName.c_str());                                // assigns file stream to the outputted file

    while (!(fout))
    {
        cout << string(15,'*') << " File Open Error "  
			 << string(15,'*') << endl; 
		cout << "==> Output file failed to open properly!!\n"; 
		cout << "==> Attempted to open file: " << outFileName << endl; 
		cout << "==> Please try again...\n"; 
		cout << string(47,'*') << endl << endl;

		fout.clear();                                              // resets output file stream for use

		cout << "Enter in the name of the output file: ";          // new file to be outputted
		cin >> outFileName;
		cout << outFileName << endl << endl;

		fout.open(outFileName.c_str());                            // tries new output file
    }

	
	//// Non-Empty File Verification
	fin.get(u);                                                    // priming read

	if (fin.eof())                                                 // for when the file is empty
	{
		cout << string(13,'*') << " Input File Is Empty "  
			 << string(13,'*') << endl; 
		cout << "==> The input file is empty.\n"; 
		cout << "==> Terminating the program.\n"; 
		cout << string(47,'*') << endl << endl;

		return 1;                                                  //ends program
	}


	//// Writing Data from Input File to Output File Pt.1
	fout << left << setw(15) << "Line Number" << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << "Total"
	     << endl << setw(15) << string(11, '-') << setw(10) << string(7, '-') << setw(10) << string(6, '-') << setw(10) << string(5, '-') << string(5, '-');

	while (!(fin.eof()))                                           // reads off all lines in file
	{
		// Character #
		if (isalpha(u))
			countL++;
		
		// Digit #
		else if (isdigit(u))
			countD++;

		// Other #
		else
			countO++;

		// Writes data to output file
		if (u == '\n')
		{
			countLine++;                                          // line counter
			countT = countL + countD + countO;                    // total numnber of characters per line

			fout << endl << left << setw(15) << countLine << setw(10) << countL << setw(10) << countD << setw(10) << countO << countT;

			sumL += countL;                                       // total sum of letters
			sumD += countD;                                       // total sum of digits
			sumO += countO;                                       // total sum of other
			sumT += countT;                                       // total sum of totals
			
			countL = countD = countO = countT = 0;                // restets counting variables
		}

		fin.get(u);                                               // next character iteration
	}


	//// Writing Data from Input File to Output File Pt.2
	perL = (sumL / float(sumT)) * 100.00;
	perD = (sumD / float(sumT)) * 100.00;
	perO = (sumO / float(sumT)) * 100.00;

	fout << endl << string(50, '-')
		 << endl << left << setw(15) << "Totals" << setw(10) << sumL << setw(10) << sumD << setw(10) << sumO << sumT;

	fout << endl << left << setw(15) << "Percent" << setw(10) << fixed << setprecision(2) << perL << setw(10) << perD << perO << endl << endl;


	//// Closing Files/File Streams
	fin.close();
	fout.close();

    return 0;
}

