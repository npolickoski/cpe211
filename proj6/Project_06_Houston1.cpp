// **************************************** 
// Program Title: Project_06 
// Project File: Project_06.cpp  
// Name: Houston Trimble
// Course Section: CPE 211L-01 
// Lab Section: 1
// Due Date: 10/4/2022
// program description: This algo. reads a file counting the number of 
// Line Numbers, Letters, Digits, Other Characters, and Total Characters
// that are givent from a .txt file 
// **************************************** 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;
int main(int argc, char *argv[ ])
{
    // Declaring Variables
	// File Stream Variables
    ifstream In_File;	                                               
    ofstream Out_File;	                                               
    string Proj_6_InF, Fout_Proj_6;                                

	// Data Extraction Variables
	char k;												           
	int iter_cnt, Lcnt, Dcnt, Ocnt, Tcnt, sumL, sumD, sumO, sumT;                 
	iter_cnt = Lcnt = Dcnt = Ocnt = Tcnt = sumL = sumD = sumO = sumT = 0;             						                                          
	double prcntL, prcntD, prcntO;                                       

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
		return 1;                                                  
	}

	// Assigns Values to Argument Names
	Proj_6_InF = argv[1]; 
	Fout_Proj_6 = argv[2];

    //// Input-File Opening Verification
    cout << endl << "Opening the input file..." << endl;
    In_File.open(Proj_6_InF.c_str());                                  
    while (!(In_File))
    {
        cout << endl << string(15,'*') << " File Open Error "  
			 << string(15,'*') << endl; 
		cout << "==> Input file failed to open properLy!!\n"; 
		cout << "==> Attempted to open file: " << Proj_6_InF << endl; 
		cout << "==> Please try again...\n"; 
		cout << string(47,'*') << endl << endl;

		In_File.clear();                                               
		cout << "Enter in the name of the input file: ";           
		cin >> Proj_6_InF;
		cout << Proj_6_InF << endl;
		In_File.open(Proj_6_InF.c_str());                              
    }

	//// Output-File Opening Verification
    cout << endl << "Opening the output file..." << endl << endl;
    Out_File.open(Fout_Proj_6.c_str());                                
    while (!(Out_File))
    {
        cout << string(15,'*') << " File Open Error "  
			 << string(15,'*') << endl; 
		cout << "==> Output file failed to open properly!!\n"; 
		cout << "==> Attempted to open file: " << Fout_Proj_6 << endl; 
		cout << "==> Please try again...\n"; 
		cout << string(47,'*') << endl << endl;

		Out_File.clear();                                              
		cout << "Enter in the name of the output file: ";          
		cin >> Fout_Proj_6;
		cout << Fout_Proj_6 << endl << endl;
		Out_File.open(Fout_Proj_6.c_str());                            
    }

	//// Non-Empty File Verification
	In_File.get(k); // priming read
	if (In_File.eof())                                                 
	{
		cout << string(13,'*') << " Input File Is Empty "  
			 << string(13,'*') << endl; 
		cout << "==> The input file is empty.\n"; 
		cout << "==> Terminating the program.\n"; 
		cout << string(47,'*') << endl << endl;
		return 1;                                                  
	}

	//// Writing Data from Input File to Output File Pt.1
	Out_File << left << setw(15) << "Line Number" << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << "Total"
	     << endl << setw(15) << string(11, '-') << setw(10) << string(7, '-') << setw(10) << string(6, '-') << setw(10) << string(5, '-') << string(5, '-');
	while (!(In_File.eof()))                                           
	{
		// Character #
		if (isalpha(k))
			Lcnt++;
		
		// Digit #
		else if (isdigit(k))
			Dcnt++;

		// Other #
		else
			Ocnt++;

		// Writes data to output file
		if (k == '\n')
		{
			iter_cnt++;                                          
			Tcnt = Lcnt + Dcnt + Ocnt;                    
			Out_File << endl << left << setw(15) << iter_cnt << setw(10) << Lcnt << setw(10) << Dcnt << setw(10) << Ocnt << Tcnt;
			sumL += Lcnt;                                       
			sumD += Dcnt;                                       
			sumO += Ocnt;                                       
			sumT += Tcnt;                                       
			Lcnt = Dcnt = Ocnt = Tcnt = 0;                
        }
		In_File.get(k);                                              
	}

	//// Writing Data from Input File to Output File Pt.2
	prcntL = (sumL / float(sumT)) * 100.00;
	prcntD = (sumD / float(sumT)) * 100.00;
	prcntO = (sumO / float(sumT)) * 100.00;

	Out_File << endl << string(50, '-')
		 << endl << left << setw(15) << "Totals" << setw(10) << sumL << setw(10) << sumD << setw(10) << sumO << sumT;
	Out_File << endl << left << setw(15) << "Percent" << setw(10) << fixed << setprecision(2) << prcntL << setw(10) << prcntD << prcntO << endl << endl;

	In_File.close();
	Out_File.close();

    return 0;
}