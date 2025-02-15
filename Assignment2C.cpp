//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment2C

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	const float moon = 1/0.0000000026;
	const float crackers = 1/40.0;
	float meters, x, y;

	cout << "[Distance Calculator]\n";
	cout << "How many meters? ";
	cin >> meters;

	x = meters / moon;
	y = meters / crackers;

	cout << "\n" << meters << " meter(s) is...";
	cout << "\n..." << x << " distance from the Moon";
	cout << "\n..." << y << " Animal Crackers long" << endl;
}
