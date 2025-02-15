//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment5A

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	int choice;
	int Ages[] = {67, 33, 47, 35, 24};
	string firstName[] = {"Mark", "Amanda", "Norman", "Steve", "Jesse"};
	string lastName[] = {"Sloan", "Bentley", "Briggs", "Sloan", "Travis"};
	string occupation[] = {"Chief of Internal Medicine", "Pathologist", "Administrator", "Hospital Security", "Surgeon Intern"};
	string license[] = {"TRUE", "TRUE", "FALSE", "FALSE", "TRUE"};

	cout << "[Community General Hospital Directory]";

	do {
		cout << "\n1) List all employees";
		cout << "\n2) Search employee records by ID";
		cout << "\n3) Search employee records by Last Name";
		cout << "\n4) Quit";
		cout << "\nChoice: ";
		cin >> choice;

		while (choice < 0 || choice > 4) {
			cout << "No option " << choice << "!";

			cout << "\nChoice: ";
			cin >> choice;
		}

		if (choice == 1) {
			for (int i = 0; i < 5; i++) {
				cout << "\n#" << i << ": " << firstName[i] << " " << lastName[i] << ", " << "Age " << Ages[i] << ", " << occupation[i] << ", " << "Medical License: " << license[i];
			}
		}
		if (choice == 2) {
			int id = 0;
			do {
				cout << "ID: ";
				cin >> id;

				if (id < 0 || id > 4) {
					cout << "Invalid ID!\n";

					cout << "ID: ";
					cin >> id;
				}
	
			    cout << "#" << id << ": " << firstName[id] << " " << lastName[id] << ", " << "Age " << Ages[id] << ", " << occupation[id] << ", " << "Medical License: " << license[id];
			} while (id < 0 || id > 4);
		}
		if (choice == 3) {
			string last;
			cout << "Last Name: ";
			cin >> last;
			bool recordFound = false;

			for (int i = 0; i < 5; i++) {
				if (lastName[i] == last) {
					cout << "#" << i << ": " << firstName[i] << " " << lastName[i] << ", " << "Age " << Ages[i] << ", " << occupation[i] << ", " << "Medical License: " << license[i] << endl;
					recordFound = true;
				}
			}

			if (!recordFound) {
				cout << "No Records Found!";
			}
		}

		cout << "\n";
	} while (choice != 4);

	if (choice == 4) {
		cout << "[Closing Directory...]" << endl;
	}
}
