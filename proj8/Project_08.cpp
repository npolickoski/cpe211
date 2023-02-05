// ****************************************
// Program Title Contact List Creation 
// Project File: Project_08.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 1 
// Due Date: 10/30/2022 
// Program Description: from a select input file, 
//      data is extracted, categorized, and printed
//      to creat a contact list of names, adresses,
//      and phone numbers                      
// ****************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


//// Stucture Declarations
struct Person
{
    string nameFirst;   // first name
    string nameLast;    // last name
    string phoneNumber; // phone number
};

struct Address
{
    string street; // residing street number and name
    string city;   // residing city
    string state;  // residing state
    int zipCode;   // residing zip code
};

struct CallerInfo
{
    Person person;   // reference to the 'Person' structure 
    Address address; // reference to the 'Address' structure   
};  



//// Function Prototypes
void fileOutHeader(ofstream&);                 // prints header to output file
void fileOutEnd(ofstream&);                    // prints the ending lines to the output file
void fileInOpen(ifstream&);                    // checks input file stream
void fileOutOpen(ofstream&);                   // checks output file stream
bool readInfo(ifstream&, CallerInfo&, bool&);  // assigns data taken from input file to structure variables
void printInfo(ofstream&, CallerInfo&);        // prints data in structure variables to output file



//// Call to main()
int main()
{
    // Variable Declaration
    ifstream fin;       // input file stream
    ofstream fout;      // output file stream
    CallerInfo profile; // CallerInfo structure variable to write data to output file (mediator)

    bool isValid = true; // validation variables
    bool isFin = true;


    // Input/Output File Initializing
    fileInOpen(fin);     // opens inout file stream

    fileOutOpen(fout);   // opens output file stream
    fileOutHeader(fout); // writes header to output file


    // Input File Data Processing
    cout << endl << "Processing information. Please Wait...." << endl;

    isFin = readInfo(fin, profile, isValid); // attributes data in input file to variables within structure

    if (!(fin))
    {
        return 1;
    }

    while (isValid & isFin)
    {
        printInfo(fout, profile); // write info to output file

        isFin = readInfo(fin, profile, isValid); // read info from input file 
    }


    // Output File Processing and I/O Closing
    if (isFin)
    {
        fileOutEnd(fout); // Last row of output file

        /// Close the files
        fin.close(); 
        fout.close();

        cout << endl << "Program has finished execution." << endl << endl;
    }
    
    return 0;
}



//// Function Definitions
void fileOutHeader(ofstream& fout) // prints header to output file
{
    fout << left << setw(7) << "Entry" << setw(20) << "Last Name" << setw(15) << "First Name"
         << setw(20) << "City" << "Phone Number"; 

    fout << endl << left << setw(7) << string(5, '-') << setw(20) << string(9, '-') << setw(15) << string(10, '-')
         << setw(20) << string(4, '-') << string(12, '-') <<  endl;

    return;
}



void fileOutEnd(ofstream& fout) // prints the ending lines to the output file
{
    fout << setw(7) << string(5,'-');
    fout << setw(20) << string(9,'-');
    fout << setw(15) << string(10,'-');
    fout << setw(20) << string(4,'-');
    fout << string(12,'-') << endl;

    return;
}



void fileInOpen(ifstream& fin) // checks input file stream
{
    // local Variable Declaration
    string fileIn;


    // Input File Processing
    do
    {
        // if (!(fin)) // for loops AFTER first iteration
        // {
        //     fin.clear();
        //     fin.ignore(INT_MAX, '\n');      
        // }

        cout << endl << "Enter the name of the input file: ";
        cin >> fileIn;
        cout << fileIn << endl;

        fin.open(fileIn.c_str());

        if (!(fin))
        {
            cout << endl << string(15, '*') << " File Open Error " << string(15, '*')
                << endl << "==> Input file failed to open properly!!"
                << endl << "==> Attempted to open file: " << fileIn
                << endl << "==> Please try again..."
                << endl << string(47, '*') << endl;
        }

    } while (!(fin)); // loops until input filestream is correct

    return;
}



void fileOutOpen(ofstream& fout) // checks output file stream
{
    // Local Variable Declaration
    string fileOut;


    // Output File Processing
    do
    {
        // if (!(fin)) // for loops AFTER first iteration
        // {
        //     fin.clear();
        //     fin.ignore(INT_MAX, '\n');      
        // }

        cout << endl << "Enter the name of the output file: ";
        cin >> fileOut;
        cout << fileOut << endl;

        fout.open(fileOut.c_str());

        if (!(fout))
        {
            cout << endl << string(15, '*') << " File Open Error " << string(15, '*')
                << endl << "==> Output file failed to open properly!!"
                << endl << "==> Attempted to open file: " << fileOut
                << endl << "==> Please try again..."
                << endl << string(47, '*') << endl;
        }

    } while (!(fout)); // loops until input filestream is correct

    return;
}



bool readInfo(ifstream& fin, CallerInfo& profileInput, bool& Continue) // assigns data taken from input file to structure variables
{
   // Reading Data from Input File
    fin >> profileInput.person.phoneNumber;          // reads phone number/priming read

    if (fin.eof())                                   // if priming read shows file is empty
    {
        Continue = false;
        return true;
    }

    fin.ignore(1, '\n');
    fin >> profileInput.person.nameLast;             // reads last name
    fin.ignore(1, '\n');
    getline(fin, profileInput.address.street, '\n'); // reads street address
    getline(fin, profileInput.address.city, '\n');   // reads city
    getline(fin, profileInput.address.state, '\n');  // reads state
    fin >> profileInput.address.zipCode;             // reads zipcode
    fin.ignore(1, '\n');
    fin >> profileInput.person.nameFirst;


    // Inout File Stream Checking
    if (!fin)
    {
        cout << endl << string(15,'*') << " File Read Error " << string(15,'*') << endl;
        cout << "==> An error has occured while reading" << endl;
        cout << "==> the input file.  Error in file content." << endl;
        cout << "==> Terminating program!!!" << endl;
        cout << string(47,'*') << endl << endl;
        
        return false;
    }

    return true;
}



void printInfo(ofstream& fout, CallerInfo& profileInput) // prints data in structure variables to output file
{
    // Counting Number of Profiles Made 
    static int profileNum = 0;
    profileNum++;


    // Wriing to Output File
    fout << left;
    fout << setw(7) << profileNum;
    fout << setw(20) << profileInput.person.nameLast;
    fout << setw(15) << profileInput.person.nameFirst;
    fout << setw(20) << profileInput.address.city;
    fout << profileInput.person.phoneNumber << endl;

    return;
}
