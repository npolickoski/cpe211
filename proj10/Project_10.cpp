// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 10
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
Date::Date() 
{
 month = JAN;
 day = 1;
 year = 2000;

 return;   
}


Date::Date(int Set_Month, int Set_Day, int Set_Year)
{
    month = Set_Month;
    day = Set_Day;
    year = Set_Year;

    return;
}


Date::Date(int Set_Month, int Set_Year)
{
    month = Set_Month;
    day = 1;
    year = Set_Year;

    return;
}


Date::Date(int Set_Year)
{
    month = JAN;
    day = 1;
    year = Set_Year;

    return;
}


// ************** TRANSFORMERS **************
void Date::SetDate(int Set_Month, int Set_Day, int Set_Year) // day/month/year initialization
{
    month = Set_Month;
    day = Set_Day;
    year = Set_Year;

    return;
}


void Date::IncrementDateDay() // increment for next day
{
    day++;
    
    switch (month)
    {
        case JAN:                               // for months w/ 31 days
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            if (day > 31)                       
            {
                month++;                        
                day = 1;                        

                if (month > 12)                 
                {
                    year++;
                    month = JAN;
                }
            }
            
            break;
        
        case FEB:                               // for february (because it's gotta be "quirky" and "different")
            if (day > 28)
            {
                month++;
                day = 1;
            }
            
            break;

        case APR:                               // for months w/ 30 days
        case JUN:
        case SEP:
        case NOV:
            if (day > 30)
            {
                month++;
                day = 1;
            }
            
            break;
    }

    return;
}


void Date::IncrementDateMonth() // conditionals for when to increment to the next month
{
    month++;

    switch (month)
    {
        case FEB:                               // current month: 28 
            if (day > 28)                       // previous month: 31 
            {
                month++;
                day -= 28;
            }
            
            break;

        case APR:                               // current month: 30
        case JUN:                               // previous month: 31
        case SEP:
        case NOV:
            if (day > 30)
            {
                month++;
                day -= 30;
            }
            
            break;
        
    }
        
        if (month > 12)
        {
            year++;
            month = JAN;
        }    

    return;
}


void Date::IncrementDateYear() // increments to next year
{
    year++;

    return;
}


void Date::IncrementDateDays(int Day_Iter) // increments to next day
{
    for (int i = 0; i < Day_Iter; i++)
    {
        Date::IncrementDateDay();
    }
    
    return;
}


// ************** OBSERVERS *******************
void Date::WriteNumberFormat() const // prints numerical values of current date
{
    cout << setfill('0') << setw(2) << month << '/' << setw(2) << day << setfill(' ') << '/' << year << endl;

    return;
}


void Date::WriteNameFormat() const // prints current date in standard order
{
    string Month;

    switch (month)
    {
        case JAN:
            Month = "January";
            break;

        case FEB:
            Month = "February";
            break;

        case MAR:
            Month = "March";
            break;
        
        case APR:
            Month = "April";
            break;
        
        case MAY:
            Month = "May";
            break;

        case JUN:
            Month = "June";
            break;

        case JUL:
            Month = "July";
            break;

        case AUG:
            Month = "August";
            break;

        case SEP:
            Month = "September";
            break;

        case OCT:
            Month = "October";
            break;

        case NOV:
            Month = "November";
            break;

        case DEC:
            Month = "December";
            break;
    }

    cout << Month << ' ' << day << ", " << year << endl;

    return;
}

