/*
CONSOLE OUTPUT/TESTING RESULTS:


----- Header Comments ----------------------------------------------------------
Exercise:
Coder: Daniel Nelson
Date:
Period: 6

Purpose:

TODO:

*/

//----- Imports -----------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//----- Global Variables --------------------------------------------------------

//----- No-Touch Functions ------------------------------------------------------

//----- My Functions ------------------------------------------------------------

//----- Driver Code -------------------------------------------------------------

/*
int main() {
	ofstream fout; //object creation ofstream is type and fout is name
	fout.open("tmp.txt");

	if (fout) {
		for (int i = 0; i < 20; i++) {
			fout << i << " ";
		}
		fout.close();

		ifstream fin; //input file
		fin.open("tmp.txt");
		if (fin) {
			for (int i = 0; i < 15; i++) {
				int value;
				//fin >> value;
				if (!(fin >> value)) {
					break;
				}
				cout << value << " ";
			}
			fin.close();
		}
		else {
			cout << "Error Opeing the input stream" << endl;
		}
	}
	else {
		cout << "Error opening the output file" << endl;
	}
}
*/
/*
int main() {
	ofstream fout; //object creation ofstream is type and fout is name
	fout.open("tmp.txt");

	if (fout) {
		for (int i = 0; i < 200; i++) {
			fout << i << endl;
		}
		fout.close();

		ifstream fin; //input file
		fin.open("tmp.txt");
		if (fin) {
			int value;
			while (fin >> value) { //using while loop
				cout << value << " ";
			}
			fin.close();
		}
		else {
			cout << "Error Opeing the input stream" << endl;
		}
	}
	else {
		cout << "Error opening the output file" << endl;
	}
}
*/

int main() {
	cout << "Please enter a filename: ";
	string filename;
	cin >> filename;

	ifstream fin; //input file
	fin.open(filename);
	if (fin) {
		char value; 
		//string value;
		while (fin.get(value))
		{ //(fin >> value)
			cout << value;
		}
		fin.close();
	}
	else {
		cout << "Error Opening the " << filename << endl;
	}
}