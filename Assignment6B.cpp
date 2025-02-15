//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment6B

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

bool check_if_sorted(int a[]);
int shuffleArray(int b[]);
void PrintArray(int c[]);

int main()
{
	int i, theArray[17] = {0};

	srand((unsigned)time(0));
	int randomNumber;

	cout << "[Random Sort]\n\n";

	//Fill the array with random values within range of 1 to 359
	for (i = 0; i < 17; i++) {
		theArray[i] = (rand() % 359) + 1;
	}

	check_if_sorted(theArray);
	shuffleArray(theArray);
	PrintArray(theArray);
	cout << "\n";
}

bool check_if_sorted(int a[]) {
	for (int i = 1; i < 17; i++) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

int shuffleArray(int b[]) {
	int newArray[17] = { 0 };

	for (int i = 0; i < 17; i++) {

	}

	return newArray;
}

void PrintArray(int c[]) {
	cout << "\nPrinting array...\n";

	for (int i = 0; i < 17; i++) {
		cout << c[i] << ", ";
	}
}