// ****************************************
// Program Title: Projectile Motion
// Project File: Project_03.cpp
// Name: Nick Polickoski
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 09/11/2022 
// Program Description: Calculates times to reach the max
//  	height and distance, the max height and distance
//      themselves, and horizontal range, all from the 
//      initial velocity and initial angle of projectile
// ****************************************

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()    
{
    //Variable Declarations
    const double G = 9.80665;     // gravity constant (m/s^2)
    const double PI = 3.14159265; // value of pi constant
    double v, aD;                 // varibales to be inputted; inital velocity (m/s) 
                                  //    and starting angle of projectile (degrees)
    double aR, tH, tD, h, d, r;   // variables set by equations


    //Inputs
    cout << string(30, '*') << endl;
    cout << "***** Projectile Motion ******" << endl;
    cout << string(30, '*') << endl;

    cout << "Enter the value for Initial Velocity (meters/sec): ";
    cin >> v;  // initial velocity input
    cout << v << endl << endl;

    cout << "Enter the value for the Starting Angle of the Projectile (degrees): "; 
    cin >> aD; // starting angle of projectile input
    cout << aD << endl << endl;


    //Equations
    aR = aD * (PI/180.0);                      // degrees to radians conversion

    tH = (v * sin(aR))/G;                      // time to reach max height equation

    tD = (2 * v * sin(aR))/G;                  // time to reach max distance equation

    h = (pow(v, 2) * pow(sin(aR), 2))/(2 * G); // max height equation 

    d = v * tD * cos(aR);                      // max distance equation

    r = pow(v, 2)/G;                           // max horizontal range equation


    //Outputs
    cout << left << setprecision(3) << setw(25) << "Time to max height:" << fixed << tH << " seconds" << endl;
    cout <<                            setw(25) << "Time to max distance:" <<        tD << " seconds" << endl;
    cout <<                            setw(25) << "Maximum height:" <<              h <<  " meters" <<  endl;
    cout <<                            setw(25) << "Maximum distance:" <<            d <<  " meters" <<  endl; 
    cout <<                            setw(25) << "Maximum range:" <<               r <<  " meters" <<  endl;

    cout << endl << string(30, '*');

    return 0; 
}
