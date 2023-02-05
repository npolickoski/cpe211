// ****************************************
// Program Title: Array Bit Manipulation
// Project File: Project_09.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 1 
// Due Date: 11/13/2022 
// Program Description:                 
// ****************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <climits>
#include <array>

using namespace std;


//// Global Constants    -------------------> notes these are NOT variables
const int MAX_ROW = 10;
const int MAX_COL = 10;
typedef int arrProto[MAX_ROW][MAX_COL]; // array prototype 


//// Function Prototypes
void openInputFile(ifstream&);                                                                                          // input file stream validation
void readData(ifstream&, int&, int&, arrProto /*array 1*/, arrProto /*array 2*/);                                       // input file data reading

void resultOR(int, int, const arrProto /*array 1*/, const arrProto /*array 2*/, arrProto /*OR array*/);                 // OR gate result
void resultAND(int, int, const arrProto /*array 1*/, const arrProto /*array 2*/, arrProto /*AND array*/);               // AND gate result
void resultXOR(int, int, const arrProto /*array 1*/, const arrProto /*array 2*/, arrProto /*XOR array*/);               // XOR gate result

void printInputArr(int, int, const arrProto /*array 1*/, const arrProto /*array 2*/);                                   // input array printing
void printOutputArr(int, int, const arrProto /*OR array*/, const arrProto /*AND array*/, const arrProto /*XOR array*/); // output array printing

int calcIntArr(int, int, const arrProto);                                                                               // binary to decimal value calculations
void printIntArr(int, int, const arrProto /*OR array*/, const arrProto /*AND array*/, const arrProto /*XOR array*/);    // decimal value printing



//// Call to Main 
int main()
{
    //// Variable Declaration
    ifstream fin;                         // input file stream 
    int rowNum, colNum;                   // row and column values

    arrProto arr1, arr2;                  // arrays #1 and #2 actual
    arrProto arrOR, arrAND, arrXOR;       // output arrays for logical gates


    //// File Opening and Data Extraction
    // Input File Initialization
    openInputFile(fin);

    // Input File Data Reading
    readData(fin, rowNum, colNum, arr1, arr2);


    //// Logical Gate Data Manipulation
    // OR
    resultOR(rowNum, colNum, arr1, arr2, arrOR);

    // AND
    resultAND(rowNum, colNum, arr1, arr2, arrAND);

    // XOR
    resultXOR(rowNum, colNum, arr1, arr2, arrXOR);


    //// Printing Data
    // Input Arrays
    printInputArr(rowNum, colNum, arr1, arr2);

    // Output Arrays
    printOutputArr(rowNum, colNum, arrOR, arrAND, arrXOR);

    // Decimal Array
    printIntArr(rowNum, colNum, arrOR, arrAND, arrXOR);


    return 0;
}



//// Function Definitions
void openInputFile(ifstream& fin) // checks validity of input file stream
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



void readData(ifstream& fin, int& rowNum, int& colNum, arrProto arr1, arrProto arr2) // reads in data from input arrays
{
    //// Read in Row/Col Number Values
    fin >> rowNum;                             // row value
    fin.ignore(INT_MAX, '\n');                 // skips comments left in the file

    fin >> colNum;                             // column value
    fin.ignore(INT_MAX, '\n');
    fin.ignore(INT_MAX, '\n');                 // twice b/c new line between row/col vals and array vals


    //// Read in Array Values
    // Variable Declaration
    int bitVal;                                // read-in value

    // Read-in Array #1
    for (int row = 0; row < rowNum; row++)     // for all rows
    {
        for (int col = 0; col < colNum; col++) // for all columns
        {            
            fin >> bitVal;
            arr1[row][col] = bitVal;
        }
    }

    // Read-in Array #2
    fin.ignore(INT_MAX, '\n');                 // ignoring line in between array data ---> //// MAY REMOVE LATER

    for (int row = 0; row < rowNum; row++)     // for all rows
    {
        for (int col = 0; col < colNum; col++) // for all columns
        {            
            fin >> bitVal;
            arr2[row][col] = bitVal;
        }
    }
    
    return;
}



void resultOR(int rowNum, int colNum, const arrProto arr1, const arrProto arr2, arrProto arrOR)
{
    for (int row = 0; row < rowNum; row++)
    {
        for (int col = 0; col < colNum; col++)
        {
            if ((arr1[row][col] == 1) || (arr2[row][col] == 1))      // if either bit is 1
            {
                arrOR[row][col] = 1;
            }
            else if ((arr1[row][col] == 0) && (arr2[row][col] == 0)) // if both bits are 0
            {
                arrOR[row][col] = 0;
            }
        }
    }

    return;
}



void resultAND(int rowNum, int colNum, const arrProto arr1, const arrProto arr2, arrProto arrAND)
{
    for (int row = 0; row < rowNum; row++)
    {
        for (int col = 0; col < colNum; col++)
        {
            if ((arr1[row][col] == 1) && (arr2[row][col] == 1))      // if both bits are 1
            {
                arrAND[row][col] = 1;
            }
            else if ((arr1[row][col] == 0) || (arr2[row][col] == 0)) // if any bit is 0
            {
                arrAND[row][col] = 0;
            }
        }
    }

    return;
}



void resultXOR(int rowNum, int colNum, const arrProto arr1, const arrProto arr2, arrProto arrXOR)
{   
    for (int row = 0; row < rowNum; row++)
    {
        for (int col = 0; col < colNum; col++)
        {
            if (arr1[row][col] == arr2[row][col])      // if both bits equal each other
            {
                arrXOR[row][col] = 0;
            }
            else if (arr1[row][col] != arr2[row][col]) // if both bits don't equal each other
            {
                arrXOR[row][col] = 1;
            }
        }
    }

    return;
}



void printInputArr(int rowNum, int colNum, const arrProto arr1, const arrProto arr2)
{
    //// Data Printing
    // Header
    cout << endl << "Initial values of the arrays processed"
         << endl << "--------------------------------------" << endl;

    cout << left << setw(2*colNum) << "Array 1" << string(4, ' ') << setw(2*colNum) << "Array 2"
         << endl << setw(2*colNum) << string(7, '-') << string(4, ' ') << setw(2*colNum) << string(7, '-') << endl;


    // Rows
    for (int row = 0; row < rowNum; row++)
    {
        for (int col1 = 0; col1 < colNum; col1++)
        {
            cout << arr1[row][col1] << ' ';               // printing array #1

            if (col1 == (colNum - 1))
            {
                cout << string(4, ' ');

                for (int col2 = 0; col2 < colNum; col2++)
                {
                    cout << arr2[row][col2] << ' ';       // printing array #2
                }

                cout << endl;                             // next row

            }
        }
    }

    return;
}



void printOutputArr(int rowNum, int colNum, const arrProto arrOR, const arrProto arrAND, const arrProto arrXOR)
{
    //// Data Printing
    // Header 
    cout << endl << "OR, AND and XOR results"
         << endl << "-----------------------";

    cout << endl << left << setw(2*colNum) << "OR" << string(4, ' ') << setw(2*colNum) << "AND" << string(4, ' ') << setw(2*colNum) << "XOR"
         << endl << left << setw(2*colNum) << "--" << string(4, ' ') << setw(2*colNum) << "---" << string(4, ' ') << setw(2*colNum) << "---" << endl;
    

    // Rows
    for (int row = 0; row < rowNum; row++)
    {
        for (int colOR = 0; colOR < colNum; colOR++)
        {
            cout << arrOR[row][colOR] << ' ';                          // printing OR array

            if (colOR == (colNum - 1))
            {
                cout << string(4, ' ');

                for (int colAND = 0; colAND < colNum; colAND++)
                { 
                    cout << arrAND[row][colAND] << ' ';                // printing AND array

                    if (colAND == (colNum - 1))
                    {
                        cout << string(4, ' ');

                        for(int colXOR = 0; colXOR < colNum; colXOR++)
                        {
                            cout << arrXOR[row][colXOR] << ' ';        // printing XOR array
                        }

                        cout << endl;                                  // next row

                    }
                }
            }
        }
    }
    
    return;
}



int calcIntArr(int row, int colNum, const arrProto standardArray)
{   
    // Initialize Variables
    int deciSum = 0; //sum of binary bits across one row in array

    // Summing Up all Bits in Row
    for (int col = 0; col < colNum; col++)
    {
        deciSum += standardArray[row][col]*pow(2, (colNum - 1) - col); // ex: 22 = (1)*2^4 + (0)*2^3 + (1)*2^2 + (1)*2^1 + (0)*2^0
    }

    return deciSum;
}



void printIntArr(int rowNum, int colNum, const arrProto arrOR, const arrProto arrAND, const arrProto arrXOR)
{
    // Initialize Variables
    int deciOR, deciAND, deciXOR; // binary to decimal sums for logic gate arrays


    //// Data Printing
    // Header
    cout << endl << endl << "Integer Equivalents for the rows"
         << endl << "of the OR, AND and XOR arrays"
         << endl << "--------------------------------";

    cout << endl << left << setw(8) << "OR" << setw(8) << "AND" << setw(8) << "XOR"
         << endl << left << setw(8) << "--" << setw(8) << "---" << setw(8) << "---" << endl;

    // Rows
    for (int row = 0; row < rowNum; row++)
    {
        deciOR = calcIntArr(row, colNum, arrOR);   // binary sum of bits in OR array
        deciAND = calcIntArr(row, colNum, arrAND); // binary sum of bits in AND array
        deciXOR = calcIntArr(row, colNum, arrXOR); // binary sum of bits in XOR array

        cout << setw(8) << deciOR
             << setw(8) << deciAND
             << setw(8) << deciXOR << endl;
    }

    return;
}

