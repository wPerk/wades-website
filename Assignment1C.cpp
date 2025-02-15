/*
Class: CSE 1321L
Section: E02
Term: Spring 2023
Instructor: Justin McClung
Name: Wade Perkins
Assignment#: Assignment1C
*/

//=================================== Assignment1C.cpp ================================
// Assignment1C
//This program asks the user for day, month (in number and word form), and year.
//Then the date is displayed in multiple formats for the user to choose from.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_month;
	int day, n_month, year;

	cout << "Enter the day (number): ";
	cin >> day;
	cout << "Enter the month (number): ";
	cin >> n_month;
	cout << "Enter the month (string): ";
	cin >> s_month;
	cout << "Enter the year (number): ";
	cin >> year;

	cout << "\nHere are some ways to represent the date: ";

	cout << "\n" << n_month << "/";
	cout << "" << day << "/";
	cout << "" << year << "";

	cout << "\n" << year << "/";
	cout << "" << day << "/";
	cout << "" << n_month << "";

	cout << "\n" << day << "/";
	cout << "" << n_month << "/";
	cout << "" << year << "";

	cout << "\n" << s_month << " ";
	cout << "" << day << ", ";
	cout << "" << year << "";

	cout << "\n" << day << " ";
	cout << "" << s_month << " ";
	cout << "" << year << "\n" << endl;
}
