/*
Class: CSE 1321L
Section: E02
Term: Spring 2023
Instructor: Justin McClung
Name: Wade Perkins
Assignment#: Assignment1B
*/

//=================================== Assignment1B.cpp ================================
// Assignment1B
// This program allows the user to enter a list of grocery items along with quantity and
// price. It the calculates the total cost for each item group and total for all items,
// then it displays these values to the user.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string item1, item2;
	int qty1, qty2;
	double price1, price2;
	double sum1, sum2, total;

	//ITEM 1
	cout << "What are you buying? ";
	getline(cin, item1);
	cout << "How many? ";
	cin >> qty1;
	cout << "What is the cost? ";
	cin >> price1;

	//ITEM 2
	cout << "\nWhat else are you buying? ";
	cin >> item2;
	cout << "How many? ";
	cin >> qty2;
	cout << "What is the cost? ";
	cin >> price2;

	//LIST
	cout << "\nYour list: ";
	cout << "\n---- ";

	cout << "\n" << item1 << " ";
	cout << "(" << qty1 << ")";
	cout << "\n$" << price1 << " ";
	sum1 = price1 * qty1;
	cout << "($" << sum1 << " total)" << endl;

	cout << "\n" << item2 << " ";
	cout << "(" << qty2 << ")";
	cout << "\n$" << price2 << " ";
	sum2 = price2 * qty2;
	cout << "($" << sum2 << " total)" << endl;

	total = sum1 + sum2;

	cout << "\nTotal Cost: $" << total << "";

	cout << "\n----\n ";
}




