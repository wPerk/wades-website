//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment3A

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	double x_coord, y_coord;

	cout << "[Cretaceous Park GIS]\n";
	cout << "X Coordinate: ";
	cin >> x_coord;
	cout << "Y Coordinate: ";
	cin >> y_coord;

	cout << "\n";

	if (x_coord > 8.0 || x_coord < 0.0) {
		cout << "WARNING: You have left the boundaries of the park.\nPlease return immediately.";
	}
	else if (y_coord > 8.0 || y_coord < 0.0) {
		cout << "WARNING: You have left the boundaries of the park.\nPlease return immediately.";
	}
	else if (x_coord >= 2.0 && x_coord <= 6.0 && y_coord >= 2.0 && y_coord <= 4.0) {
		cout << "You are at the T. Rex Lake\n";				//Area B
	}
	else if (x_coord >= 0.0 && x_coord <= 2.0 && y_coord >= 5.0 && y_coord <= 8.0) {
		cout << "You are at the Pterodactyl Aviary\n";		//Area C
	}
	else if (x_coord >= 2.0 && x_coord <= 4.0 && y_coord >= 6.0 && y_coord <= 8.0) {
		cout << "You are at the Visitor's Center\n";		//Area D
	}
	else if (x_coord >= 5.0 && x_coord <= 8.0 && y_coord >= 5.0 && y_coord <= 8.0) {
		cout << "You are at the Deinonychus Pen\n";			//Area E
	}
	else {
		cout << "You are at the Triceratops Grasslands\n";	//Area A
	}
}
