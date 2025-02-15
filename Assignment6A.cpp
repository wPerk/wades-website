// Class: CSE 1321L
// Section: E02
// Term: Spring 2023
// Instructor: Justin McClung
// Name: Wade Perkins
// Assignment#: Assignment6A

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int main() {
	int i, loopsL = 1, loopsB = 1, target = 0;
	vector <int> arrayMil;
	arrayMil.resize(1000019);

	srand((unsigned)time(0));
	int randomNumber;

	cout << "[Linear Vs. Binary Search]";

	// FILL ARRAY WITH 1 MILLION VALUES IN REVERSE
	for (i = 1000018; i >= 0; i--) {
		arrayMil[i] = i;
	}

	target = (rand() % 1000019);

	// Linear Search Algorithm
	bool isFound = false;
	for (int i = 0; i < 1000019; i++) {
		// If we find a match, set isFound to true and BREAK
		if (arrayMil[i] == target) {
			isFound = true;
			break;
		}
		loopsL++;
	}

	// Binary Search Algorithm
	int low = 0;
	int high = 1000018;
	int mid = (high + low) / 2;
	bool found = false;
	while (high >= low) {
		mid = (low + high) / 2;
		if (target < arrayMil[mid]) {
			high = mid - 1;
		}
		else if (target == arrayMil[mid]) {
			found = true;
			break;
		}
		else
			low = mid + 1;
		loopsB++;
	}

	cout << "\nThe target value is " << target;
	cout << "\nLinear Search: " << loopsL << " loop(s)";
	cout << "\nBinary Search: " << loopsB << " guess(es)";

	// DETERMINE WHICH METHOD IS FASTER
	if (loopsL > loopsB) {
		cout << "\nBinary Search is faster this time!";
	}
	else if (loopsL < loopsB) {
		cout << "\nLinear Search is faster this time!";
	}
	else if (loopsL == loopsB) {
		cout << "\nBinary and Linear Search methods are tied!";
	}
	cout << "\n";
}
