// ****************************************
// Program Title: Phone book
// Project File: Project_08.cpp 
// Name: Jonathan Shreve
// Course Section: CPE-211-01
// Lab Section: 1
// Due Date: 10/30/22
// Program Description: Description of
// What the program does. 
// **************************************** 

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>
#include <climits>
#include <cmath>

using namespace std;  


//// Structure Declarations

struct Struct_Personal_Info
{
    string Name_First;
    string Name_Last;
    string Phone_Number;
};

 
struct Struct_Address
{
    string Street;
    string City;
    string State;
    int Zip_Code;
};


struct Struct_Phone_Book
{
    Struct_Personal_Info Personal_Info;
    
    Struct_Address Address;
    
};



//// Function Prototypes

void Print_Header(ofstream&);
void Print_End(ofstream&);
void Open_In_File(ifstream&);
void Open_Out_File(ofstream&);
bool Read_Info(ifstream&, Struct_Phone_Book&, bool&);
void Write_Info(ofstream&, Struct_Phone_Book&);



int main() 
{ 
    /// Variables
    ifstream F_In;
    ofstream F_Out;
    Struct_Phone_Book Entry_1;
    bool Valid_To_Cont = true;
    bool Is_F_In_Good = true;

    /// Open the input file
    Open_In_File(F_In);
    
    /// Open the output file
    Open_Out_File(F_Out); 

    /// Print header to output file
    Print_Header(F_Out); 

    /// Read info from input file 
    cout << endl << "Processing information. Please Wait...." << endl;
    Is_F_In_Good = Read_Info(F_In, Entry_1, Valid_To_Cont);

    if (!F_In)
    {
        return 1;
    }
    

    while (Valid_To_Cont & Is_F_In_Good)
    {
        /// Write info to output file
        Write_Info(F_Out, Entry_1);

        /// Read info from input file 
        Is_F_In_Good = Read_Info(F_In, Entry_1, Valid_To_Cont);
    }

    if (Is_F_In_Good)
    {
        // Last row of output file
        Print_End(F_Out);

        /// Close the files
        F_In.close(); 
        F_Out.close();

        cout << endl << "Program has finished execution." << endl << endl;
    }
    // else if (!Is_F_In_Good)
    // {
    //     /* code */
    // }
    
    return 0; 
}



//// Funtion Definitions

void Print_Header(ofstream& F_Out)
{
    /// Output 
    F_Out << left;
    F_Out << setw(7) << "Entry";
    F_Out << setw(20) << "Last Name";
    F_Out << setw(15) << "First Name";
    F_Out << setw(20) << "City";
    F_Out << "Phone Number" << endl;

    F_Out << setw(7) << string(5,'-');
    F_Out << setw(20) << string(9,'-');
    F_Out << setw(15) << string(10,'-');
    F_Out << setw(20) << string(4,'-');
    F_Out << string(12,'-') << endl;
    return;
}



void Print_End(ofstream& F_Out)
{
    F_Out << setw(7) << string(5,'-');
    F_Out << setw(20) << string(9,'-');
    F_Out << setw(15) << string(10,'-');
    F_Out << setw(20) << string(4,'-');
    F_Out << string(12,'-') << endl;
    return;
}



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
            cout << string(47,'*') << endl << endl;
        }

    } while (!F_In);

    return;
}



void Open_Out_File(ofstream& F_Out)
{
    string filename;
    cout << endl << "Enter the name of the output file: ";
    cin >> filename;
    cout << filename << endl;
    F_Out.open(filename);
    return;
}



bool Read_Info(ifstream& F_In, Struct_Phone_Book& Entry, bool& Continue)
{   
    
    // Probably need a priming read to see if file is empty

    F_In >> Entry.Personal_Info.Phone_Number;
    if (F_In.eof())
    {
        Continue = false;
        return true;
    }
    F_In.ignore(1,'\n');
    F_In >> Entry.Personal_Info.Name_Last;
    F_In.ignore(1,'\n');
    getline(F_In,Entry.Address.Street,'\n');
    getline(F_In,Entry.Address.City,'\n');
    getline(F_In,Entry.Address.State,'\n');
    F_In >> Entry.Address.Zip_Code;
    F_In.ignore(1,'\n');
    F_In >> Entry.Personal_Info.Name_First;

    if (!F_In)
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



void Write_Info(ofstream& F_Out, Struct_Phone_Book& Phone_Book_Entry)
{
    static int Entry_Num = 0;

    Entry_Num++;

    F_Out << left;
    F_Out << setw(7) << Entry_Num;
    F_Out << setw(20) << Phone_Book_Entry.Personal_Info.Name_Last;
    F_Out << setw(15) << Phone_Book_Entry.Personal_Info.Name_First;
    F_Out << setw(20) << Phone_Book_Entry.Address.City;
    F_Out << Phone_Book_Entry.Personal_Info.Phone_Number << endl;

    return;
}