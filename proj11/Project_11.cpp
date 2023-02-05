// ****************************************
// Program Title: Class Statics Report
// Project File: Project_11.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 1 
// Due Date: 12/04/2022 
// Program Description: takes in class data for every student in
//      an academic class outputs a formal report of the avergaes
//      and grades of the individual students, their associative
//      letter grades, the highest and lowest averages of the class,
//      and a histogram graph for the number of grades in the class.                
// ****************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <climits>

using namespace std;


//// Structures
struct Student
{
    string nameL;     // student last name
    string nameF;     // student first name
    double Avg;       // average grade value
    char letterGrade; // letter grade conversion of student average
};

struct ClassData
{
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;  

    double classAvg = 0.00;
    double lowAvg = 100;
    double highAvg = 0.00;
};


//// Function Prototypes
void fileInOpen(ifstream&);                                // checks input file stream
bool Is_fileIn_EOF(ifstream&, int&);                       // checks if input file is empty
double average(ifstream&, int&);                           // average of all grades read in
void readInData(ifstream&, int&, Student&);                // reads in data to structure variables
void writeHeader();                                        // header for file output
void writeInData_Student(Student&, ClassData&, int&);            // outputs individual student data to terminal
void writeInData_Class(Student&, ClassData&, int&);              // outputs class info to terminal
 

//// Call to Main
int main()
{
    // Initialize Variables
    ifstream fin;         // input file stream
    int gradeNum;         // inital extraction for number of grades per student in input file
    bool IsEmpty = false; // initalize program control value


    // Open Input File
    fileInOpen(fin);


    // Conditional for Empty Input File Check
    IsEmpty = Is_fileIn_EOF(fin, gradeNum);

    if (IsEmpty)
    {
        return 1;
    }


    // Reading in Input File Data/Outputting to Terminal
    Student stud;                        // initalized student variable - no data assigned to it
    ClassData classStats;                // initalized class data variable - no data assigned to it
    int studNum = 0;                     // initalized number of student counter

    writeHeader();
    
    do
    {
        readInData(fin, gradeNum, stud);       // reads in data form input file for one particular student instance

        if (!(fin.eof()))
        {
            writeInData_Student(stud, classStats, studNum); // outputs individual student info
        }

    } while(!(fin.eof()));

    writeInData_Class(stud, classStats, studNum);

    return 0;
}


// // Function Definitions
void fileInOpen(ifstream& fin) // checks input file stream
{
    // Local Variable Declaration
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
                << endl << string(47, '*') << endl
                << endl << "Try Again..." << endl;
        }

    } while (!(fin)); // loops until input filestream is correct

    return;
}



bool Is_fileIn_EOF(ifstream& fin, int& gradeNum)
{   
    // Extraction of First Value in Input File
    fin >> gradeNum;

    // Check for Empty File
    if (fin.eof())
    {
        cout << endl << string(16, '*') << " File Is Empty " << string(16, '*')
                << endl << "==> Input file is empty"
                << endl << "==> No information to process"
                << endl << string(47, '*') << endl << endl;
        
        return true;
    }

    return false;
}



double average(ifstream& fin, int& gradeNum) // structure function that calculates average grade value
{
    // Initalize Variables
    double grade, sum, avg;

    // Summation of All grade Entries
    for (int i = 0; i < gradeNum; i++)
    {
        fin >> grade;
        sum += grade;
    }

    avg = double(sum)/double(gradeNum);

    return avg;
}



void readInData(ifstream& fin, int& gradeNum, Student& stud)
{   
    // Read In Data
    fin >> stud.nameL;
    fin >> stud.nameF;

    stud.Avg = average(fin, gradeNum);

    fin.ignore(INT_MAX, '\n');

    return;
}



void writeHeader()
{
    cout << endl << left << setw(4) << "#" << setw(15) << "Last" << setw(10) << "First" << setw(9) << "Average" << "Grade"
         << endl         << setw(4) << "-" << setw(15) << string(4, '-') << setw(10) << string(5, '-') << setw(9) << string(7, '-') << string(5, '-');

    return;
}



void writeInData_Student(Student& stud, ClassData& classStats, int& studNum)
{
    // Letter Grade Conditionals
    if (stud.Avg >= 90.00)
    {
        stud.letterGrade = 'A';
        classStats.countA++;
    }
    else if (stud.Avg >= 80.00)
    {
        stud.letterGrade = 'B';
        classStats.countB++;
    }
    else if (stud.Avg >= 70.00)
    {
        stud.letterGrade = 'C';
        classStats.countC++;
    }
    else if (stud.Avg >= 60.00)
    {
        stud.letterGrade = 'D';
        classStats.countD++;
    }
    else if (stud.Avg < 60.00)
    {
        stud.letterGrade = 'F';
        classStats.countF++;
    }


    // Info Output
    studNum++;

    cout << endl << left << setw(4) << studNum 
         << setw(15) << (stud.nameL).substr(0, 12) 
         << setw(10) << (stud.nameF).substr(0, 7) 
         << setw(9) << fixed << setprecision(2) << stud.Avg << stud.letterGrade;



    // Averages Calulation for Each Student Instance
    if (stud.Avg > classStats.highAvg) // for class's highest average
    {
        classStats.highAvg = stud.Avg;
    }

    if (stud.Avg < classStats.lowAvg)  // for class's lowest average
    {
        classStats.lowAvg = stud.Avg;
    }

    classStats.classAvg += stud.Avg;   // for total class average (prior ot number of entries division)

    return;
}



void writeInData_Class(Student& stud, ClassData& classStats, int& studNum)
{
    // Class Data Averages Output
    cout << endl << endl << left << setfill('.') << fixed << setprecision(2) << setw(25) << "Class Average" << (double(classStats.classAvg) / double(studNum))
         << endl << setw(25) << "Highest Average" << classStats.highAvg
         << endl << setw(25) << "Lowest Average" << classStats.lowAvg << endl
         << setfill(' ');


    // Histogram Output
    cout << endl << right << setw(18) << "Grade Histogram"  << endl 
         << "           1         2" << endl 
         << "  12345678901234567890"

         << endl << "A:" << string(classStats.countA, '*')
         << endl << "B:" << string(classStats.countB, '*')
         << endl << "C:" << string(classStats.countC, '*')
         << endl << "D:" << string(classStats.countD, '*')
         << endl << "F:" << string(classStats.countF, '*')

         << endl << endl;

    return;
}

