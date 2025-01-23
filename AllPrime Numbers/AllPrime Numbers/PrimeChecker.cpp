/*
----- Header Comments ----------------------------------------------------------
Exercise: PrimeChecker
Coder: Daniel Nelson
Date:1/25/2022
Period: 6

Purpose:

TODO:

*/

//----- Imports -----------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//----- Global Variables --------------------------------------------------------

//----- No-Touch Functions ------------------------------------------------------

//----- My Functions ------------------------------------------------------------

bool isWhole(double input) {
	if (floor(input) == input)
		return true;
	else
		return false;
}

bool checkIfPrime(double number) {
	double counting = 1;
	int correct = 0;
	if (number < 0) {
		return false;
	}//negatives are auto not prime
	if (number == 1) {
		return true;
	}//if 1 automatically returns true
	while (counting <= number) {
		double whole = number / counting;
		if (isWhole(whole)) {
			correct++;
		}
		counting++;
	}
	if (correct == 2) {
		return true;
	}
	else {
		return false;
	}
}

//----- Driver Code -------------------------------------------------------------

int main() {
	cout << "What is the number you would like to check for prime answers?\n";
	int number;
	cin >> number;
	bool isIt = checkIfPrime(number);
	if (isIt == true) {
		cout << number << " is a prime number!";
	}
	else {
		cout << number << " is not a prime number ;-;";
	}
}