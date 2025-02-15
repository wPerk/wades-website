//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment7B

#include <iostream>;
#include <string>;
using namespace std;

class Pixel {
	public:
		int red;
		int green;
		int blue;

	Pixel(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}
};

int main()
{
	int width, height, choice;
	int red, grn, blu;
	int newColor, length;
	Pixel** data1 = new Pixel * [width];
	Pixel array1[12][12];

	cout << "[Color Art Program]\n";
	cout << "Enter an image width: ";
	cin >> width;
	cout << "Enter an image height: ";
	cin >> height;
	cout << "Enter the fill color's red value: ";
	cin >> red;
	cout << "Enter the fill color's green value: ";
	cin >> grn;
	cout << "Enter the fill color's blue value: ";
	cin >> blu;

	do {
		cout << "What will you do?\n";
		cout << "1) Fill in a pixel\n";
		cout << "2) Fill in a line\n";
		cout << "3) Print the image\n";
		cout << "4) Quit?\n";
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				//Fill in a pixel

				

				break;
			case 2:
				//Fill in a line

				

				break;
			case 3:
				//Print the image
				cout << "PPM Image Contents\n";
				cout << "P3\n";
				cout << width << " " << height;
				cout << "255";
				break;
		}

	} while (choice != 4);
}
