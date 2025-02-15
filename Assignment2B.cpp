//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment2B

#include <iostream>;
#include <string>;
#include <cmath>;
#include <iomanip>;
using namespace std;

int main()
{
	float vid, speed, sum, newVid, saves;

	//video time format is minutes.seconds
	cout << "What is the original video time? ";
	cin >> vid;
	cout << "What is the playback speed factor? ";
	cin >> speed;

	//Convert video time into seconds:1
	//...use modulo to isolate # of minutes
	int x = floor(vid);
	//...convert minutes to seconds
	int y = (vid - x) * 100;
	int sec = 60 * x + y;
	//...add result to number of original seconds
	sum = sec + (vid - x);

	newVid = sec / speed;
	saves = sum - newVid;

	cout << "\nThe new video time would be " << setprecision(0) << fixed << newVid << " second(s).";
	cout << "\nThat saves you " << setprecision(0) << fixed << saves << " second(s) from the original video speed." << endl;
}
