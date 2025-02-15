//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment2A

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num1, num2, mod;
	int sum, diff, prod, quot;
	int mod1, mod2, mod3, mod4;

	cout << "First number: ";
	cin >> num1;
	cout << "Second Number: ";
	cin >> num2;
	cout << "Number for Modulo Operation: ";
	cin >> mod;

	sum = num1 + num2;
	mod1 = sum % mod;

	diff = num1 - num2;
	mod2 = diff % mod;

	prod = num1 * num2;
	mod3 = prod % mod;

	quot = num1 / num2;
	mod4 = quot % mod;


	cout << "\n" << num1 << " + " << num2 << " = " << sum << ". The remainder if divided by " << mod << " is " << mod1 << ".";
	cout << "\n" << num1 << " - " << num2 << " = " << diff << ". The remainder if divided by " << mod << " is " << mod2 << ".";
	cout << "\n" << num1 << " * " << num2 << " = " << prod << ". The remainder if divided by " << mod << " is " << mod3 << ".";
	cout << "\n" << num1 << " / " << num2 << " = " << quot << " (Approximately). The remainder if divided by " << mod << " is " << mod4 << "." << endl;
}








/*
	int p, g, n, r;

	cout << "How many people are there? ";
	cin >> p;
	cout << "How many groups do you want? ";
	cin >> g;

	n = p / g;
	r = p % g;

	cout << "If we divide " << p << " people into " << g << " groups evenly, " << r;
	cout << " person/people will be left without a group.\n" << endl;
*/