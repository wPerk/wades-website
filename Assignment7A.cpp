//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment7A

#include <iostream>
#include <string>
using namespace std;

class RoshamboPlayer {
	public:						//Private by default
		string PlayerName;
		int RoLimit;
		int ShamBoLimit;

	//Generic constructor
	RoshamboPlayer() {
        RoLimit = 30;
		ShamBoLimit = 60;
    }

    //Normal constructor
	RoshamboPlayer(int inRo, int inShamBo) {
		RoLimit = inRo;
		ShamBoLimit = inShamBo;
    }

    void getName(string playername) {
		PlayerName = playername;
    }

    bool playRound(string attack) {
        int round;
        string play;

        //Get random number
        round = rand() % 101;
        
        //Machine play assignment
		if (round <= RoLimit) {
			play = "Ro";
		}
		else if (round >= ShamBoLimit) {
			play = "Bo";
		}
		else {
			play = "Sham";
		}

        cout << PlayerName << " chose " << play << "! ";

        //Game rules
		if (play == "Ro" && attack == "Ro") {
			return false;
		}
		else if (play == "Ro" && attack == "Sham") {
			return true;
		}
		else if (play == "Ro" && attack == "Bo") {
			return false;
		}
		else if (play == "Sham" && attack == "Sham") {
			return false;
		}
		else if (play == "Sham" && attack == "Ro") {
			return false;
		}
		else if (play == "Sham" && attack == "Bo") {
			return true;
		}
		else if (play == "Bo" && attack == "Bo") {
			return false;
		}
		else if (play == "Bo" && attack == "Ro") {
			return true;
		}
		else {
			return false;
		}
    }
};

int main()
{
	int choice, result;
	string attack;
	RoshamboPlayer opponent;

	cout << "\n[Ro-Sham-Bo Player]\nWho do want to face?\n";
	cout << "1) R. Dorothy\n2) Johnny 5\nOpponent: ";
	cin >> choice;
	
	//Initialize Opponent Stats
	if (choice == 1) {
		cout << "\nYour Opponent is R. Dorothy";
		RoshamboPlayer opponent(30, 60);			//Create Opponent 1
		opponent.getName("R. Dorothy");
	}
	else {
		cout << "\nYour Opponent is Johnny 5";
		RoshamboPlayer opponent(40, 85);			//Create Opponent 2
		opponent.getName("Johnny 5");
	}

	//Main Game Logic
	while (1) {
		cout << "\n1) Play a Round?\n2) Quit?\nChoice: ";
		cin >> choice;

		if (choice == 1) {

		}
		else if (choice == 2) {
			break;
		}
		else {
			cout << "Invalid Choice\n";
			continue;
		}

		while (1) {
			cout << "\nEnter an Attack: ";
			cin >> attack;

			if (attack == "Ro" || attack == "Sham" || attack == "Bo") {
				result = opponent.playRound(attack);
				break;
			}
			else {
				cout << "Invalid attack!";
			}
		}

		(result == false) ? cout << "You lose...\n" : cout << "You win!\n";
	}

	cout << "\nGame Over\n";
}
