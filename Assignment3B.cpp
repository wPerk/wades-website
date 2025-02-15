//Class: CSE 1321L
//Section: E02
//Term: Spring 2023
//Instructor: Justin McClung
//Name: Wade Perkins
//Assignment#: Assignment3B

#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	int w, h, s, a, b, c;
	int x = 0;	// 'x' needs to be initialized here because there's a chance it could have a value of nothing

	cout << "[Image Encoding Checker]\n";
	cout << "What is the image width? ";
	cin >> w;
	cout << "What is the image height? ";
	cin >> h;
	cout << "What is the file size (in bytes)? ";
	cin >> s;

	//check that info is valid
	if (w < 0 || h < 0 || s < 0) {
		cout << "\nThe information is invalid - please re-enter it.\n" << endl;
	}

	int tPixels = w * h;
	int tFile = tPixels * 3;

	cout << "\nTotal File Size: " << tFile << "\n\n";

	//What calcualtions am I performing here?
	//Note: 1 byte = 8 bits
	//		each pixel takes up 3 bytes of space
	// 1, 2, or 4 * 3 = 3, 6, 12
	// multiply the width and height

	a = tFile % 8;
	b = tFile % 16;
	c = tFile % 32;

	// How do I determine which of the BPC options (8, 16, 32) is correct?
	if (a == 0) {
		x = 8;
	}
	else if (b == 0) {
		x = 16;
	}
	else if (c == 0) {
		x = 32;
	}

	switch (x) {
		case 8:
		cout << "The RGB image is encoded with 8 bits per channel." << endl;
		break;

		case 16:
		cout << "The RGB image is encoded with 16 bits per channel." << endl;
		break;

		case 32:
		cout << "The RGB image is encoded with 32 bits per channel." << endl;
		break;

		default:
		cout << "hello (:\n" << endl;
		break;
	}
}
