// ****************************************
// Program Title: OR, AND, XOR, Row int
// Project File: Project_09.cpp 
// Name: Jonathan Shreve
// Course Section: CPE-211-01
// Lab Section: 1
// Due Date: 11/13/22
// Program Description: Reads in 2 input 
// arrays from an input file and calculates
// and ouputs OR, AND, and XOR applied to
// the arrays and the integer row 
// equivalents of the output arrays.
// **************************************** 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array> 
#include <cmath>
#include <climits>

using namespace std; 

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
typedef int Bit_Array[MAX_ROWS][MAX_COLS];




//// Function Prototypes 

void Open_In_File(ifstream&);
void Read_Data(ifstream&,int&,int&,Bit_Array,Bit_Array);
void OR(int,int,const Bit_Array,const Bit_Array,Bit_Array);
void AND(int,int,const Bit_Array,const Bit_Array,Bit_Array);
void XOR(int,int,const Bit_Array,const Bit_Array,Bit_Array);
void Print_Input_Array(int,int,const Bit_Array,const Bit_Array);
void Print_Output_Array(int,int,const Bit_Array,const Bit_Array,const Bit_Array);
int Row_Int_Value(int,int,const Bit_Array);
void Print_Int_Array(int,int,const Bit_Array,const Bit_Array,const Bit_Array);



int main() 
{ 
    /// Variables
    ifstream F_In;
    int Num_Rows;
    int Num_Columns;
    Bit_Array In_Array_1;
    Bit_Array In_Array_2;
    Bit_Array OR_Array;
    Bit_Array AND_Array;
    Bit_Array XOR_Array;


    // Open the input file
    Open_In_File(F_In);

    // Read number of rows and columns and input arrays
    Read_Data(F_In,Num_Rows,Num_Columns,In_Array_1,In_Array_2);

    // Calculate the OR_Array
    OR(Num_Rows,Num_Columns,In_Array_1,In_Array_2,OR_Array);

    // Calculate the AND_Array
    AND(Num_Rows,Num_Columns,In_Array_1,In_Array_2,AND_Array);

    // Calculate the XOR_Array
    XOR(Num_Rows,Num_Columns,In_Array_1,In_Array_2,XOR_Array);

    // Print input arrays
    Print_Input_Array(Num_Rows,Num_Columns,In_Array_1,In_Array_2);

    // Print result arrays
    Print_Output_Array(Num_Rows,Num_Columns,OR_Array,AND_Array,XOR_Array);

    // Print base 10 array
    Print_Int_Array(Num_Rows,Num_Columns,OR_Array,AND_Array,XOR_Array);

    return 0; 
}



//// Function Definitions

void Open_In_File(ifstream& F_In)
{
    string filename;
        
    do
    {
        cout << endl << "Enter the name of the input file: ";
        cin >> filename;
        cout << filename << endl;
        F_In.open(filename);

        if (!F_In)
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << endl << string(15,'*') << " File Open Error " << string(15,'*') << endl;
            cout << "==> Input file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << filename << endl;
            cout << "==> Please try again..." << endl;
            cout << string(47,'*') << endl;
        }

    } while (!F_In);

    return;
}



void Read_Data(ifstream& F_In,int& Num_Rows,int& Num_Columns,Bit_Array Array_1,Bit_Array Array_2)
{
    int Element;

    F_In >> Num_Rows;
    F_In.ignore(INT_MAX,'\n');
    F_In >> Num_Columns;
    // cout << Num_Rows << ' ' << Num_Columns << endl;
    // for loop(s) to read in values to the array
    for (int i = 0; i < 2; i++)
    {
        F_In.ignore(INT_MAX,'\n');
    }
    
    for (int Row = 0; Row < Num_Rows; Row++)
    {
        for (int Col = 0; Col < Num_Columns; Col++)
        {
            F_In >> Element;
            Array_1[Row][Col] = Element;
            // cout << Array_1[Row][Col] << endl;
        }
        
    }
    
    F_In.ignore(INT_MAX,'\n');
    // cout << endl;

    for (int Row = 0; Row < Num_Rows; Row++)
    {
        for (int Col = 0; Col < Num_Columns; Col++)
        {
            F_In >> Element;
            Array_2[Row][Col] = Element;
            // cout << Array_2[Row][Col] << endl;
        }
        
    }

    // cout << Array_1[0][0];
    return;
}



void OR(int Row_Count,int Col_Count,const Bit_Array Array_1,const Bit_Array Array_2,Bit_Array OR_Array)
{
    for (int Row = 0; Row < Row_Count; Row++)
    {
        for (int Col = 0; Col < Col_Count; Col++)
        {
            if ((Array_1[Row][Col] == 1)|(Array_2[Row][Col] == 1))
            {
                OR_Array[Row][Col] = 1;
            }
            else
            {
                OR_Array[Row][Col] = 0;
            }
        }       
    }
    
    return;
}



void AND(int Row_Count,int Col_Count,const Bit_Array Array_1,const Bit_Array Array_2,Bit_Array AND_Array)
{
    for (int Row = 0; Row < Row_Count; Row++)
    {
        for (int Col = 0; Col < Col_Count; Col++)
        {
            if ((Array_1[Row][Col] == 0)|(Array_2[Row][Col] == 0))
            {
                AND_Array[Row][Col] = 0;
            }
            else
            {
                AND_Array[Row][Col] = 1;
            }
        }       
    }
    
    return;
}



void XOR(int Row_Count,int Col_Count,const Bit_Array Array_1,const Bit_Array Array_2,Bit_Array XOR_Array)
{
    for (int Row = 0; Row < Row_Count; Row++)
    {
        for (int Col = 0; Col < Col_Count; Col++)
        {
            if (Array_1[Row][Col] == Array_2[Row][Col])
            {
                XOR_Array[Row][Col] = 0;
            }
            else
            {
                XOR_Array[Row][Col] = 1;
            }
        }       
    }
    
    return;
}



void Print_Input_Array(int Row_Count,int Col_Count,const Bit_Array Array_1,const Bit_Array Array_2)
{
    cout << endl << "Initial values of the arrays processed" << endl;
    cout << string(38,'-') << endl;
    cout << left;
    cout << setw(2*Col_Count) << "Array 1" << string(4,' ') << setw(2*Col_Count) << "Array 2" << endl;
    cout << setw(2*Col_Count) << string(7,'-') << string(4,' ') << setw(2*Col_Count) << string(7,'-') << endl;


    for (int Row = 0; Row < Row_Count; Row++)
    {
        for (int Col = 0; Col < Col_Count; Col++)
        {
            cout << Array_1[Row][Col] << ' ';

            if (Col == (Col_Count - 1))
            {
                cout << string(4,' ');

                for (int Col = 0; Col < Col_Count; Col++)
                {
                    cout << Array_2[Row][Col] << ' ';
                }
                
                cout << endl;
            }
        }
    }
    
    cout << endl;

    return;
}



void Print_Output_Array(int Row_Count,int Col_Count,const Bit_Array OR_Array,const Bit_Array AND_Array,const Bit_Array XOR_Array)
{
    cout << "OR, AND and XOR results" << endl;
    cout << string(23,'-') << endl;
    cout << left;
    cout << setw(2*Col_Count) << "OR" << string(4,' ');
    cout << setw(2*Col_Count) << "AND" << string(4,' ');
    cout << setw(2*Col_Count) << "XOR" << endl;

    cout << setw(2*Col_Count) << string(2,'-') << string(4,' ');
    cout << setw(2*Col_Count) << string(3,'-')<< string(4,' ');
    cout << setw(2*Col_Count) << string(3,'-')<< endl;

    for (int Row = 0; Row < Row_Count; Row++)
    {
        for (int Col = 0; Col < Col_Count; Col++)
        {
            cout << OR_Array[Row][Col] << ' ';

            if (Col == (Col_Count - 1))
            {
                cout << string(4,' ');

                for (int Col = 0; Col < Col_Count; Col++)
                {
                    cout << AND_Array[Row][Col] << ' ';

                    if (Col == (Col_Count - 1))
                    {
                        cout << string(4,' ');

                        for (int Col = 0; Col < Col_Count; Col++)
                        {
                            cout << XOR_Array[Row][Col] << ' ';
                        }
                        
                        cout << endl;
                    }
                }
            }
        }
    }

    return;
}



int Row_Int_Value(int Row,int Col_Count,const Bit_Array Array)
{
    // Variables
    int Row_Eq_B_10 = 0;

    for (int Col = 0; Col < Col_Count; Col++)
    {
        Row_Eq_B_10 += Array[Row][Col]*pow(2,(Col_Count - 1) - Col);
    }

    return Row_Eq_B_10;
}



void Print_Int_Array(int Row_Count,int Col_Count,const Bit_Array OR_Array,const Bit_Array AND_Array,const Bit_Array XOR_Array)
{
    // Variables
    int Row_Eq_OR;
    int Row_Eq_AND;
    int Row_Eq_XOR;

    cout << endl << endl;
    cout << "Integer Equivalents for the rows" << endl;
    cout << "of the OR, AND and XOR arrays" << endl;
    cout << string(32,'-') << endl;
    cout << left;
    cout << setw(8) << "OR" << setw(8) << "AND" << setw(8) << "XOR" << endl; 
    cout << setw(8) << string(2,'-') << setw(8) << string(3,'-') << setw(8) << string(3,'-') << endl;

    for (int Row = 0; Row < Row_Count; Row++)
    {
        Row_Eq_OR = Row_Int_Value(Row,Col_Count,OR_Array);
        Row_Eq_AND = Row_Int_Value(Row,Col_Count,AND_Array);
        Row_Eq_XOR = Row_Int_Value(Row,Col_Count,XOR_Array);

        cout << setw(8) << Row_Eq_OR << setw(8) << Row_Eq_AND << setw(8) << Row_Eq_XOR << endl;
        
    }

    return;
}