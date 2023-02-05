// *************************************************************
// main function declaration to run the class funcitons
// DO NOT MODIFY THIS FILE
// **************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h" 

using namespace std;

int main()
{
    cout << endl << string(40,'*') << endl;
	cout << "Example of the two output methods:\n";
    cout << "Number Format:   11/05/2017\n";
    cout << "Name Format: November 5, 2017\n";
    cout << string(40,'*') << endl << endl;

    // construct two objects of the class - one using 
    // default date the other using paramertized constructor
    //
    cout << "Constructor Test: Default\n";
    cout << "-------------------------\n";
    //cout << "      Default Constructor\n";
    Date date1;
    date1.WriteNumberFormat();
    date1.WriteNameFormat();
    cout << string(40,'*') << endl << endl;

    cout << "Constructor Test: 3 Parameters\n";
    cout << "------------------------------\n";
    //cout << "      Parameterized Constructor(3 arguments)\n";
    Date date2(6,20,1970);
    date2.WriteNumberFormat();
    date2.WriteNameFormat();
    cout << string(40,'*')  << endl << endl;

    cout << "Constructor Test: 2 Parameters\n";
    cout << "------------------------------\n";
    //cout << "      Parameterized Constructor(2 arguments)\n";
    Date date3(8,1980);
    date3.WriteNumberFormat();
    date3.WriteNameFormat();
    cout << string(40,'*') << endl << endl;
    
    cout << "Constructor Test: 1 Parameter\n";
    cout << "-----------------------------\n";
	//cout << "      Parameterized Constructor(1 argument)\n";
    Date date4(1990);
    date4.WriteNumberFormat();
    date4.WriteNameFormat();
    cout << string(40,'*') << endl << endl << endl;
	
    // verifying SetDate date function
    cout << string(40,'*') << endl;
    cout << "Set Date Test\n";
    cout << "-------------\n";
    date1.SetDate(10,6,2000);
    date1.WriteNumberFormat();
    date1.WriteNameFormat();
    cout << string(40,'*') << endl << endl << endl;
    
	// Test the output for correct date and month
	// formatting
	
    cout << string(40,'*') << endl;
    cout << "Testing every month for correct output\n";
    cout << "--------------------------------------\n";
    
    //cout << string(40,'*') << endl;
    for (int i = 1; i<=12; i++)
    {
        date1.SetDate(i,i,2018);
        date1.WriteNumberFormat();
        date1.WriteNameFormat();
        cout << string(40,'*') << endl;
    }
	cout << endl;

	// incrementation function testing

	// increment by one day at a time test
	
    cout << endl << string(40,'*') << endl;
    cout << "Increment 1 day at a time test\n";
    cout << "------------------------------\n";
    cout << "Incrementing 1 day at a time, but\n";
    cout << "Only showing the output every 30 days.\n\n";
    date1.SetDate(1,1,2000);
    cout << "starting date: ";
    date1.WriteNumberFormat();
    cout << endl;
    for (int i = 1; i <420;i++)
    {
        date1.IncrementDateDay();
        if (i%30 == 0)
        {
            cout << "Date + 30:  ";
            date1.WriteNumberFormat();
        }
     }
    cout << "Final Date: "; 
    date1.WriteNumberFormat();
	cout << string(40,'*') << endl << endl;
	
	// increment by one month
	
	cout << string(40,'*') << endl;
    cout << "Increment 1 month at a time test\n";
    cout << "--------------------------------\n";
    date1.SetDate(6,18,2000);
	cout << "starting date:  ";
    date1.WriteNumberFormat();
    
    for (int i = 1; i <14;i++)
    {
        date1.IncrementDateMonth();
        cout << "Date + 1 month: ";
        date1.WriteNumberFormat();
     }
    cout << "Final Date:     "; 
    date1.WriteNumberFormat();
	cout << string(40,'*') << endl;
	// Increment by one year
	
	cout << endl << string(40,'*') << endl;
    cout << "Increment 1 year at a time test\n";
    cout << "-------------------------------\n";
    date1.SetDate(10,4,2000);
	cout << "starting date: ";
    date1.WriteNumberFormat();
	for (int i = 1; i <5;i++)
    {
        date1.IncrementDateYear();
        cout << "Date + 1 year: ";
        date1.WriteNumberFormat();
     }
    cout << "Final Date:    "; 
            date1.WriteNumberFormat();
	cout << string(40,'*') << endl;	
		
	// increment by n days
	cout << endl << string(40,'*') << endl;
    cout << "Increment n days test\n";
    cout << "---------------------\n";
    date1.SetDate(2,4,2000);
	cout << "starting date:  ";
    date1.WriteNumberFormat();
    
	for (int i = 1; i <8;i++)
    {
        date1.IncrementDateDays(17*i);
        cout << "Date + " << (17*i) << " days: ";
        date1.WriteNumberFormat();
     }
    cout << "Final Date:      "; 
            date1.WriteNumberFormat();
	cout << endl;
	return 0;
}
