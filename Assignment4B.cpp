//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment4B

//NOTES:
// i corresponds to rows
// j corresponds to columns

#include <iostream>;
using namespace std;

int main()
{
	int i, j, sqrsize, border, sqrcolor, brdrcolor;

	//Request, verify, and store user input
	cout << "Enter the size of the square: ";
	cin >> sqrsize;
	while (sqrsize < 0) {
		cout << "Invalid input!";
		cout << "\nEnter the size of the square: ";
		cin >> sqrsize;
	}

	cout << "Enter the size of the border: ";
	cin >> border;
	while (border < 0) {
		cout << "Invalid input!";
		cout << "\nEnter the size of the border: ";
		cin >> border;
	}

	cout << "Enter the color of the square: ";
	cin >> sqrcolor;
	while (sqrcolor < 0 || sqrcolor > 1) {
		cout << "Invalid input!";
		cout << "\nEnter the color of the square: ";
		cin >> sqrcolor;
	}

	cout << "Enter the color of the border: ";
	cin >> brdrcolor;
	while (brdrcolor < 0 || brdrcolor > 1) {
		cout << "Invalid input!";
		cout << "\nEnter the color of the border: ";
		cin >> brdrcolor;
	}

	//Variable that fits border around square
	int var = sqrsize + 2 * border;

	cout << "PBM File Contents:" << endl;
	cout << "PI" << endl;
	cout << "" << var << " " << var << endl;

	if (sqrcolor == 1 && brdrcolor == 0) {
		for (i = 0; i < var; i++) {
			//Create border around top of square
			if (i < border) {
				for (j = 0; j < var; j++) {
					cout << "0 ";
				}
			}
			//Create border around sides of square
			else if (i >= border && i < (var - border)) {
				for (j = 0; j < border; j++) {
					cout << "0 ";
				}
				for (j = border; j < (var - border); j++) {
					cout << "1 ";
				}
				for (j = var - border; j < var; j++) {
					cout << "0 ";
				}
			}
			//Create border around bottom of square
			else {
				for (j = 0; j < var; j++) {
					cout << "0 ";
				}
			}

			cout << "\n";
		}
	}
	else if (sqrcolor == 1 && brdrcolor == 1) {
		for (i = 0; i < var; i++) {
			//Create border around top of square
			if (i < border) {
				for (j = 0; j < var; j++) {
					cout << "1 ";
				}
			}
			//Create border around sides of square
			else if (i >= border && i < (var - border)) {
				for (j = 0; j < border; j++) {
					cout << "1 ";
				}
				for (j = border; j < (var - border); j++) {
					cout << "1 ";
				}
				for (j = var - border; j < var; j++) {
					cout << "1 ";
				}
			}
			//Create border around bottom of square
			else {
				for (j = 0; j < var; j++) {
					cout << "1 ";
				}
			}

			cout << "\n";
		}
	}
	else if (sqrcolor == 0 && brdrcolor == 1) {
		for (i = 0; i < var; i++) {
			//Create border around top of square
			if (i < border) {
				for (j = 0; j < var; j++) {
					cout << "1 ";
				}
			}
			//Create border around sides of square
			else if (i >= border && i < (var - border)) {
				for (j = 0; j < border; j++) {
					cout << "1 ";
				}
				for (j = border; j < (var - border); j++) {
					cout << "0 ";
				}
				for (j = var - border; j < var; j++) {
					cout << "1 ";
				}
			}
			//Create border around bottom of square
			else {
				for (j = 0; j < var; j++) {
					cout << "1 ";
				}
			}

			cout << "\n";
		}
	}
	else if (sqrcolor == 0 && brdrcolor == 0) {
		for (i = 0; i < var; i++) {
			//Create border around top of square
			if (i < border) {
				for (j = 0; j < var; j++) {
					cout << "0 ";
				}
			}
			//Create border around sides of square
			else if (i >= border && i < (var - border)) {
				for (j = 0; j < border; j++) {
					cout << "0 ";
				}
				for (j = border; j < (var - border); j++) {
					cout << "0 ";
				}
				for (j = var - border; j < var; j++) {
					cout << "0 ";
				}
			}
			//Create border around bottom of square
			else {
				for (j = 0; j < var; j++) {
					cout << "0 ";
				}
			}

			cout << "\n";
		}
	}
}