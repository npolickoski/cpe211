// ****************************************
// Program Title: Password Generator
// Project File: Project_04.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 1 
// Due Date: 09/18/2022 
// Program Description: creates a unique password for
//      a user from their first name, last name, and
//      3 special words.
// ****************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Initializing Variables
	string name_full, wd1, wd2, wd3;          // user inputs
	string name_first, name_last;             // split of 'name_full'

	const string SPECIAL = "!@#$%^&*(){}[]?"; // special characters for password
	
	

	//Inputs
	cout << endl << string(60, '*') << endl
	     << string(22, ' ') << "Password Generator" << endl             // header
	     << string(60, '*') << endl;

	cout << "Enter user's first and last names separated by a space: "; // name input
	getline(cin, name_full);
	cout << endl << "name = " << name_full << endl << endl;
	
	cout << "Enter the first word: ";                                   // first word
	cin >> wd1;
	cout << endl << "first word = " << wd1 << endl << endl;

	cout << "Enter the second word: ";                                  // second word
	cin >> wd2;
	cout << endl << "second word = " << wd2 << endl << endl;

	cout << "Enter the third word: ";                                   // third word
	cin >> wd3; 
	cout << endl << "third word = " << wd3 << endl << endl;



	//First Name/Last Name Separation
	name_first = name_full.substr(0, name_full.find(' '));                          //getting just the first name from the full name
	name_last = name_full.substr(name_full.find(' ') + 1 , name_full.length() - 1); //getting just the last name from the full name



	//Outputs
	cout << string(60, '*') << endl
	     << left << setw(8) << "Word#" << setw(10) << "Length" << setw(20) << "Word" << endl
	     << setw(8) << string(5, '-') << setw(10) << string(6, '-') << setw(20) << string(4, '-') << endl

	     << setw(8) << '1' << setw(10) << wd1.length() << setw(20) << wd1 << endl
		 << setw(8) << '2' << setw(10) << wd2.length() << setw(20) << wd2 << endl
		 << setw(8) << '3' << setw(10) << wd3.length() << setw(20) << wd3 << endl

	     << setw(8) << string(5, '-') << setw(10) << string(6, '-') << setw(20) << string(4, '-') << endl << endl;
		 // output header with columns

	cout << "Average word length = " << fixed << setprecision(2) << showpoint  
	     << (wd1.length() + wd2.length() + wd3.length()) / 3.00 << endl << endl;
	     // prints average word length of all three user-chosen words

	cout << "password = " 
	     << name_first.at(0) << name_last.at(0) << name_full.length() 
	     << SPECIAL.at(name_full.length() % SPECIAL.length())
		 // prints the first and last initials of the user's name, as well as the length 
		 //   of thir full name and a special character

	     << wd1.at(0) << wd1.at(wd1.length() - 1) << wd1.length() << SPECIAL.at(wd1.length() % SPECIAL.length())
		 // prints the first and last letters of the first word, the word length, and a special character

		 << wd2.at(0) << wd2.at(wd2.length() - 1) << wd2.length() << SPECIAL.at(wd2.length() % SPECIAL.length())
		 // prints the first and last letters of the second word, the word length, and a special character

		 << wd3.at(0) << wd3.at(wd3.length() - 1) << wd3.length() << SPECIAL.at(wd3.length() % SPECIAL.length()) << endl;
		 // prints the first and last letters of the third word, the word length, and a special character

	cout << string(60, '*') << endl << endl;


	return 0;
}
