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

void Date::SetDate(int Set_Month, int Set_Day, int Set_Year)
{
    month = Set_Month;
    day = Set_Day;
    year = Set_Year;
    return;
}



void Date::IncrementDateDay()
{
    day++;
    
    switch (month)
    {
    case JAN:                               // Cases with 31 days
    case MAR:
    case MAY:
    case JUL:
    case AUG:
    case OCT:
    case DEC:
        if (day > 31)                       // Conditional to handle month roll over
        {
            month++;                        // Increment the month
            day = 1;                        // Set the day to the first of the month

            if (month > 12)                 // Conditional to handle year roll over
            {
                year++;
                month = JAN;
            }
        }
        
        break;
    
    case FEB:
        if (day > 28)
        {
            month++;
            day = 1;
        }
        
        break;

    case APR:                               // Cases with 30 days
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



void Date::IncrementDateMonth()
{
    month++;

    switch (month)
    {
    case FEB:                               // Current month: 28 days | Previous month: 31 days
        if (day > 28)
        {
            month++;
            day -= 28;
        }
        
        break;

    case APR:                               // Current month: 30 days | Previous month: 31 days
    case JUN:
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



void Date::IncrementDateYear()
{
    year++;
    return;
}



void Date::IncrementDateDays(int Day_Iter)
{
    for (int i = 0; i < Day_Iter; i++)
    {
        Date::IncrementDateDay();
    }
    
    return;
}

// ************** OBSERVERS *******************

void Date::WriteNumberFormat() const
{
    cout << setfill('0') << setw(2) << month << '/' << setw(2) << day << setfill(' ') << '/' << year << endl;
    return;
}



void Date::WriteNameFormat() const
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