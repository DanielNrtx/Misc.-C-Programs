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

int array1() {
	int arr[3]{5, 10, 15};

	/*
	arr[0] = 5;
	arr[1] = 10;
	arr[2] = 15;
	
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	*/

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}

int main() {
	const int NUM_ITEMS = 10;
	const string QUOTE1 = "Quote1.txt";
	
	const int ITEM_WIDTH = 20;


	ifstream fin;
	fin.open(QUOTE1);
	if (!fin) {
		cout << "Error opening " << QUOTE1 << endl;
	}

	string items[NUM_ITEMS]{
		"carpet",
		"hardwood",
		"tile",
		"countertop",
		"shower",
		"sinks",
		"faucets",
		"windows",
		"stairs",
		"paint"
	};
	
	int quote1[NUM_ITEMS];
	/*
	for (int i = 0; i < NUM_ITEMS; i++) {
		fin >> quote1[i];
	}

	cout << left;
	cout << setw(ITEM_WIDTH) << "Items" << "quote1\n\n";

	for (int i = 0; i < NUM_ITEMS; i++) {
		cout << setw(ITEM_WIDTH) << items[i] << "$" << quote1[i] << endl;
	}
	*/

	bool error = false;
	for (int i = 0; i < NUM_ITEMS; i++) {
		if (!(fin >> quote1[i])) {
			cout << "Error: " << QUOTE1 << "has unsifficient data" << endl;
			error = true;
			break;
		}
	}
	fin.close();

	if (!error) {
		cout << left;
		cout << setw(ITEM_WIDTH) << "Items" << "quote1\n\n";

		int total = 0;
		for (int i = 0; i < NUM_ITEMS; i++) {
			total += quote1[i];
			cout << setw(ITEM_WIDTH) << items[i] << "$" << quote1[i] << endl;
		}
		cout << setw(ITEM_WIDTH) << "total" << "$" << total << endl;
	}
}