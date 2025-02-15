//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment3C

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	int option;

	cout << "[Cretaceous Park Dialog]\n";

	cout << "Oh no, the power has gone out at Cretaceous Park!\n";
	cout << "1) What does that mean?\n";
	cout << "2) No, I just turned the light off\n";
	cin >> option;

	if (option == 2) {
		cout << "\nOh thank goodness!\n";
	}
	else {
		cout << "\nThe dinosaurs will get loose... again...\n";
		cout << "1) Life finds a way...\n";
		cout << "2) What do we do?\n";
		cin >> option;

		if (option == 1) {
			cout << "\nThat's not helpful right now!\nWe have to evacuate the park!\n";
		}
		else {
			cout << "\nWe have to evacuate the park!\n";
		}
		
	}
}
