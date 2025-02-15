//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment4A

//QUESTIONS:
// - What condition needs to go in my while loops?
//

//NOTES:
// - don't need for loops in while loop
// - sample output #3 stops at -120 because it can't count down to 0 from a negative number

#include <iostream>;
#include <math.h>;
using namespace std;

int main()
{
	int i, choice, startNum, endNum;

	cout << "What loop do you want to use?\n";
	cout << "1) A loop that might run zero or more times\n";
	cout << "2) A loop that will always run at least once\n";
	cout << "3) A loop with a predetermined start and end\n";
	cin >> choice;
	cout << "Your choice: " << choice;

	//1. A loop that might run zero or more times, endNum = 0
	if (choice == 1) {

		cout << "\nWhat's your start number? ";
		cin >> startNum;
		cout << "Counting: ";

		while (startNum >= 0) {
			cout << startNum;
			cout << ", ";
			startNum--;
		}
		cout << "\n";
	}
	//2. A loop that will always run at least once,  endNum = 0
	else if (choice == 2) {
		cout << "\nWhat's your start number? ";
		cin >> startNum;
		cout << "Counting: ";

		do {
			cout << startNum;
			cout << ", ";
			startNum--;
		} while (startNum >= 0);

		cout << "\n";
	}
	//3. A loop with a predetermined start and end
	else if (choice == 3) {
		cout << "\nWhat's your start number? ";
		cin >> startNum;
		cout << "What's your end number? ";
		cin >> endNum;
		cout << "Counting: ";
		
		//Count backwards
		if (startNum > endNum) {
			for (i = 0; i <= abs(endNum - startNum); i++) {
				if (i == abs(endNum - startNum)) {
					cout << startNum - i << endl;
					break;
				}
				cout << startNum - i << ", ";
			}
		}
		//Count forwards
		else if (startNum < endNum) {
			for (i = 0; i <= abs(endNum - startNum); i++) {
				if (i == abs(endNum - startNum)) {
					cout << startNum + i << endl;
					break;
				}
				cout << startNum + i << ", ";
			}
		}
	}
}