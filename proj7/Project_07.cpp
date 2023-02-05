// ****************************************
// Program Title: Option Selection
// Project File: Project_07.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 1 
// Due Date: 10/18/2022 
// Program Description: program creates options that
//         that may be selected by the user, including
//         a value of PI estimator, coin flipper, and
//         5-sided die roller.
// ****************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

//// Function Prototypes
void menu();             // prints the menu and selection screen
int int_obtain();        // validates the number input by the user and returns said number
void calc_pi();          // estimates the value of PI using the Monte Carlo Method
void coin_flip();        // flips a coin and prints the percent of each side appeared to the total number of flips
void die_toss();         // rolls a 5-sided die and prints percent each side appeared to the total number of rolls


//// Call to Main
int main()
{
    //// Initializing Variables
    int seed;                 // seed #
    int option;               // user chosen option

    //// Initializing Seed Number
    cout << endl << "Enter in the seed(integer > 0) for the random number generator: "; 
    cin >> seed; 
    cout << seed << endl;     // echo print
    srand(seed);              // use the seed entered to initialize the generator 

	//// Choice Obtaining
    menu();
    option = int_obtain();    // priming read

    while (option != 4)
    {

        switch (option)
        {
            case 1:
            {
                calc_pi();
                break;
            }

            case 2:
            {
                coin_flip();
                break;
            }

            case 3:
            {
                die_toss();
                break;
            }

            default:
            {
                cout << endl << string(15, '*') << " Invalid Integer " << string(15, '*') << endl
                     << "==> Invalid integer entered." << endl
                     << "==> Please try again..." << endl
                     << string(47, '*') << endl;                  
            }
        }

        menu();
        option = int_obtain();
    }

    cout << endl << "Exit selected.  Exiting the program now..." << endl << endl;

	return 0;
}


//// Function Definitions
void menu() // prints header and options
{
    // Header
    cout << endl << string(24, '*') << endl
         << string(5, '*') << " Menu Options " << string(5, '*')
         << endl << string(24, '*') << endl;

    // Options
    cout << "1) Approximate PI" << endl
         << "2) Flip a fair coin" << endl
         << "3) Toss a fair 5-sided die" << endl
         << "4) Exit" << endl
         << string(24, '*')
         
         << endl << endl << "Enter your choice: ";

    return;
}



int int_obtain() // checks for proper input
{   
    // Initialize Variables
    int choice;
    char ch;

    // Input Request
    cin >> choice;
    
    // When Input is not an Int
    while (cin.fail())
    {
        cin.clear();
        cin >> ch;
        cout << ch << endl;
        cin.ignore(RAND_MAX, '\n');

        cout << endl << string(14, '*') << " Invalid Character " << string(14, '*')
             << endl << "==> Invalid character(s) entered."
             << endl << "==> Please try again..."
             << endl << string(47, '*') << endl;

        menu();

        cin >> choice;
    }
        
    cout << choice << endl;

    return choice;
}



void calc_pi() // estimates PI
{
    // Variable Declaration
    int iterations, ins; // # of iterations
    double x, y, estPI;  // PI estimation
    ins = 0;

    // Variable Assignment
    cout << endl << "Monte Carlo Method for finding PI has been selected" << endl << endl
         << "Number of iterations: ";
    cin >> iterations;

    // Input Validation
    if (!(cin))
    {
        cin.clear();
        cin.ignore(RAND_MAX, '\n');

        cout << endl << string(14, '*') << " Invalid Character " << string(14, '*')
             << endl << "==> Invalid character(s) entered."
             << endl << "==> Please try again..."
             << endl << string(47, '*') << endl;

        return;
    }

    cout << iterations << endl;

    // Random Generator
    for (int i = 0; i < iterations; i++)
    {
        x = double(rand())/double(RAND_MAX);
        y = double(rand())/double(RAND_MAX);

        if (double(sqrt((x * x) + (y * y))) <= 1.0)
            ins++;   
    }

    // Output
    estPI = 4.00 * (double(ins)/double(iterations));

    cout << endl << string(10, '*') << " Option 1: Calculating PI " << string(10, '*') << endl
         << "For " << iterations << " iterations, pi is about " << fixed << setprecision(6) << estPI << endl
         << string(46, '*') << endl;

    return;
}



void coin_flip() // flips a coin
{
    // Variable Declaration
    int flips, countH, countT;
    double side, perH, perT;
    countH = countT = 0;

    // Variable Assignment
    cout << endl << "Flipping of a fair coin has been selected" << endl << endl
         << "How many flips of the coin? ";
    cin >> flips;
    
    // Input Validation
    if (!(cin))
    {
        cin.clear();
        cin.ignore(RAND_MAX, '\n');

        cout << endl << string(14, '*') << " Invalid Character " << string(14, '*')
             << endl << "==> Invalid character(s) entered."
             << endl << "==> Please try again..."
             << endl << string(47, '*') << endl;

        return;
    }

    cout << flips << endl;

    // Random Generator
    for (int i = 0; i < flips; i++)                 // number of flips
    {
        side = double(rand())/double(RAND_MAX);     // the "coin"

        if (side > 0.5)                             // when "coin" lands on heads
            countH++;

        else if (side <= 0.5)                       // when "coin" lands on tails
            countT++;
    }

    // Output
    perH = (double(countH)/double(flips)) * 100.00; // percentage for heads
    perT = (double(countT)/double(flips)) * 100.00; // percentage for heads

    cout << endl << string(10, '*') << " Option 2: Flipping a Coin " << string(10, '*') << endl
         << "For " << flips << " flips of a fair coin:" << endl
         << "Heads percentage: " << fixed << setprecision(4) << perH << endl
         << "Tails percentage: " << fixed << setprecision(4) << perT << endl
         << string(47, '*') << endl;

    return;
}



void die_toss() // tosses a die
{
    // Variable Declaration
    int rolls, count1, count2, count3, count4, count5;
    double side, per1, per2, per3, per4, per5;
    count1 = count2 = count3 = count4 = count5 = 0;

    // Variable Assignment
    cout << endl << "Tossing of a fair 5-sided die has been selected" << endl << endl
         << "How many times do you want to roll the die? ";
    cin >> rolls;

    // Input Validation
    if (!(cin))
    {
        cin.clear();
        cin.ignore(RAND_MAX, '\n');

        cout << endl << string(14, '*') << " Invalid Character " << string(14, '*')
             << endl << "==> Invalid character(s) entered."
             << endl << "==> Please try again..."
             << endl << string(47, '*') << endl;

        return;
    }

    cout << rolls << endl << endl;

    // Random Generator
    for (int i = 0; i < rolls; i++)                 
    {
        side = double(rand())/double(RAND_MAX);     

        if (side < 0.2)                         // side #1                            
            count1++;

        else if ((side >= 0.2) && (side < 0.4)) // side #2                      
            count2++;

        else if ((side >= 0.4) && (side < 0.6)) // side #3                       
            count3++;

        else if ((side >= 0.6) && (side < 0.8)) // side #4                       
            count4++;

        else if ((side >= 0.8))                 // side #5                       
            count5++;

    }

    // Output
    per1 = (double(count1)/double(rolls)) * 100.00; // percentage of side 1
    per2 = (double(count2)/double(rolls)) * 100.00; // percentage of side 2
    per3 = (double(count3)/double(rolls)) * 100.00; // percentage of side 3
    per4 = (double(count4)/double(rolls)) * 100.00; // percentage of side 4
    per5 = (double(count5)/double(rolls)) * 100.00; // percentage of side 5

    cout << string(10, '*') << " Option 3: Tossing a Die " << string(10, '*') << endl
         << "For " << rolls << " rolls of a fair die:" << endl
         << "Side 1 percentage: " << fixed << setprecision(4) << per1 << endl
         << "Side 2 percentage: " << fixed << setprecision(4) << per2 << endl
         << "Side 3 percentage: " << fixed << setprecision(4) << per3 << endl
         << "Side 4 percentage: " << fixed << setprecision(4) << per4 << endl
         << "Side 5 percentage: " << fixed << setprecision(4) << per5 << endl
         << string(45, '*') << endl;

    return;
}

