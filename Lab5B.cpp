//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment5B

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	int width, height, color, choice;
	int row, col, newColor, length;
	string direction;

	cout << "[KSU Image Manipulation Program]\n";
	cout << "Enter an image width: ";
	cin >> width;
	cout << "Enter an image height: ";
	cin >> height;
	cout << "Enter the fill color: ";
	cin >> color;

	do {
		cout << "\nWhat will you do?";
		cout << "\n1) Fill in a pixel";
		cout << "\n2) Fill in a line";
		cout << "\n3) Print the image";
		cout << "\n4) Quit";
		cout << "\nChoice? ";
		cin >> choice;

		while (choice > 5 || choice < 0) {
			cout << "No option" << choice << "!";
		}

		int** data1 = new int* [width];

		for (int i = 0; i < width; i++) {
			data1[i] = new int[height];
		}

		//Need to fill the array with values
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				data1[i][j] = color;
			}
		}

		cout << "\n";

		if (choice == 1) {
			cout << "Row: ";
			cin >> row;
			cout << "Column: ";
			cin >> col;
			cout << "New Color: ";
			cin >> newColor;

			if (row < width && col < height) {
				data1[row][col] = newColor;

				cout << "\nPGM Image Contents";
				cout << "\nP2\n";
				cout << width << " " << height;
				cout << "\n255";
				cout << "\n";

				//Print the values stored in the array
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cout << "" << data1[i][j] << " ";
					}
					cout << "\n";
				}
			}
		}
		else if (choice == 2) {
			//string direction;

			cout << "Row: ";
			cin >> row;
			cout << "Column: ";
			cin >> col;
			cout << "New Color: ";
			cin >> newColor;
			cout << "Length: ";
			cin >> length;
			cout << "Direction: ";
			cin >> direction;

			if (row < width && col < height) {

				if (direction == "up") {
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							data1[i][j] = newColor;
						}
					}

					//Print the values stored in the array
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							cout << "" << data1[i][j] << " ";
						}
						cout << "\n";
					}
				}
				else if (direction == "down") {

				}
			}

/*
			switch direction {
				case "up":
					int count = 0;
					while (count < length || row - count > 0) {
						data1[row - count][col] = newColor;
						count++;
					}
			}
*/

		}
		else if (choice == 3) {
			cout << "\nPGM Image Contents";
			cout << "\nP2\n";
			cout << width << " " << height;
			cout << "\n255";
			cout << "\n";

			//Print the values stored in the array
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					cout << "" << data1[i][j] << " ";
				}
				cout << "\n";
			}
		}
			
	} while (choice != 4);

	if (choice == 4) {
		cout << "\n[Exiting KSU Image Manipulation Program]\n";
	}
}