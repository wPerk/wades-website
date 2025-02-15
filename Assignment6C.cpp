//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment6C

#include <iostream>
#include <string>
using namespace std;

int surprise_function(int a, int b);
float surprise_function(float a, float b);
double surprise_function(double a, double b);
char surprise_function(char a, char b);
bool surprise_function(bool a, bool b);

int main()
{
	int i;
	string userType, val1, val2;

	cout << "[Overload Surprise Function]";
	cout << "\nWhat data type do you want to enter? ";
	cin >> userType;
	
	if (userType == "integer") {
		int int1, int2;
		//Addition
		cout << "Value #1: ";
		cin >> int1;
		cout << "Value #2: ";
		cin >> int2;

		cout << "\nCalling surprise_function()...";
		cout << surprise_function(int1, int2);
	}
	else if (userType == "float") {
		float float1, float2;
		//Division
		cout << "Value #1: ";
		cin >> float1;
		cout << "Value #2: ";
		cin >> float2;

		cout << "\nCalling surprise_function()...";
		cout << surprise_function(float1, float2);
	}
	else if (userType == "double") {
		double doub1, doub2;
		//Modulus
		cout << "Value #1: ";
		cin >> doub1;
		cout << "Value #2: ";
		cin >> doub2;

		cout << "\nCalling surprise_function()...";
		cout << surprise_function(doub1, doub2);
	}
	else if (userType == "char") {
		char char1, char2;
		//Concatenation (return as string)
		cout << "Value #1: ";
		cin >> char1;
		cout << "Value #2: ";
		cin >> char2;

		cout << "\nCalling surprise_function()...";
		cout << surprise_function(char1, char2);
	}
	else if (userType == "boolean") {
		bool bool1, bool2;
		//Result of AND
		cout << "Value #1: ";
		cin >> bool1;
		cout << "Value #2: ";
		cin >> bool2;

		cout << "\nCalling surprise_function()...";
		cout << surprise_function(bool1, bool2);
	}
	cout << "\n";
}

int surprise_function(int a, int b) {
	cout << "\nThe result is ";
	return a + b;
}

float surprise_function(float a, float b) {
	cout << "\nThe result is ";
	return a / b;
}

double surprise_function(double a, double b) {
	cout << "\nThe result is ";
	return a % b;
}

char surprise_function(char a, char b) {
	cout << "\nThe result is ";
	return a + b;
}

bool surprise_function(bool a, bool b) {
	cout << "\nThe result is ";
	return (a && b);
}