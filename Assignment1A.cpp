/*
Class: CSE 1321L
Section: E02
Term: Spring 2023
Instructor: Justin McClung
Name: Wade Perkins
Assignment#: Assignment1A
*/

//=================================== Assignment1A.cpp ================================
// Assignment1A
// This program takes color values entered by the user, calculates the inverted color
// and displays these results in two forms.

#include <iostream>
using namespace std;

int main()
{
	int red, grn, blu;
	int inv_red, inv_grn, inv_blu;
	float r, g, b;

	// a) Ask the user to individually enter in three values between 0 to 255
	// b) Read those three values in
	cout << "Enter a red value (0-255): ";
	cin >> red;
	cout << "\nEnter a green value (0-255): ";
	cin >> grn;
	cout << "\nEnter a blue value (0-255): ";
	cin >> blu;
	
	// c) Invert each number
	inv_red = 255 - red;
	inv_grn = 255 - grn;
	inv_blu = 255 - blu;

	// d) Display the results
	cout << "The inverted color is ";
	cout << "red=" << inv_red << ", ";
	cout << "green=" << inv_grn << ", ";
	cout << "blue=" << inv_blu << endl;

	//e) Convert the inverted colors to floating point numbers'
	 r = inv_red / 255.0;
	 g = inv_grn / 255.0;
	 b = inv_blu / 255.0;

	// f) Display those results
	cout << "With floating points, that would be ";
	cout << "red=" << r << ", ";
	cout << "green=" << g << ", ";
	cout << "blue=" << b << endl;

}





