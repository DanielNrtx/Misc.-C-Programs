/*
FILe OUTPUT/TESTING RESULTS:

Nucleotides in the sequence:
1. Adenine
2. Thymine
3. Cytosine
4. Guanine
Enter your choice : 0
ERROR: Valid choices are from 1 to 4
Enter your choice : Enter your choice : 5
ERROR: Valid choices are from 1 to 4
Enter your choice : Enter your choice : 4
There are 5847 occurences of Guanine
Enter occurence: 1
Occurence 1 of Guanine is at postion 1 of the sequence
------------------------------------------------------------------------------------
Nucleotides in the sequence:
1. Adenine
2. Thymine
3. Cytosine
4. Guanine
Enter your choice : 1
There are 8892 occurences of Adenine
Enter occurence: 2225
Occurence 2225 of Adenine is at postion 7165 of the sequence
--------------------------------------------------------------------------------------
Error Opening /dnaCout.txt
DNA sequence analysis :
29782 nucleotides in the sequence

Sequence breakdown:
Adenine: 8892     29.86%
Thymine: 9581     29.86%
Cytosine: 5462    18.34%
Guanine: 5847     19.63%

Nucleotides in the sequence:
1. Adenine
2. Thymine
3. Cytosine
4. Guanine
Enter your choice : 2
There are 9581 occurences of Thymine
Enter occurence: 5
Occurence 5 of Thymine is at postion 10 of the sequence
*/

/*
----- Header Comments ----------------------------------------------------------
Exercise: DNA Test
Coder: Daniel Nelson
Date:
Period: 6

Purpose: counting dna

TODO:

*/

//----- Imports -----------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//----- Global Variables --------------------------------------------------------

const string SEQUENCE = "dnaSequence.txt";
const string DNACOUNT = "dnaCout.txt";
const int SIZE_INCREMENT = 100;

//----- Functions ---------------------------------------------------------------

//increases size of array of chars
char* growArr(char* dna, int& size) {
	int newSize = size + SIZE_INCREMENT;
	char* newArr = new char[newSize];
	for (int i = 0; i < size; i++) {
		newArr[i] = dna[i];
	}
	if (dna != NULL) {
		delete[] dna;
	}
	size = newSize;
	return newArr;
}

//increaes size of array of ints
int* growArr(int* dna, int& size) {
	int newSize = size + SIZE_INCREMENT;
	int* newArr = new int[newSize];
	for (int i = 0; i < size; i++) {
		newArr[i] = dna[i];
	}
	if (dna != NULL) {
		delete[] dna;
	}
	size = newSize;
	return newArr;
}

//reads through text and converts it into an array and adds to the number of nucleotides count
char* readDataText(char* dna, int& maxSize, int& a, int& t, int& c, int& g) {
	ifstream in;
	in.open(SEQUENCE);
	if (!in) {
		cout << "ERROR FAILED to open " << SEQUENCE << endl;
	}
	else {
		int size = 0;
		dna = growArr(dna, size);

		int numRead = 0;
		for (char nucleo; in >> nucleo; numRead++) {
			if (numRead == size) {
				dna = growArr(dna, size);
			}
			if (nucleo == 'A') {
				a++;
			}
			else if (nucleo == 'T') {
				t++;
			}
			else if (nucleo == 'C') {
				c++;
			}
			else if (nucleo == 'G') {
				g++;
			}

			dna[numRead] = nucleo;
		}
		in.close();
		maxSize = numRead;
		return dna;
	}
	return 0;
}

//finds locations of the certain neucliotide and stores into array
int* findLocations(char* dna, int* location, int maxSize, char nucleotide) {
	int count = 0;
	for (int i = 0; i < maxSize; i++) {
		if (dna[i] == nucleotide) {
			location[count] = i;
			count++;
		}
	}
	return location;
}

//menus with outputs
void outPutData(int a, int* locationA, int t, int* locationT, int c, int* locationC, int g, int* locationG) {
	int choice = 0;
	cout << "Nucleotides in the sequence:\n1. Adenine\n2. Thymine\n3. Cytosine\n4. Guanine\n";
	while (choice < 1 || choice > 4) {
		cout << "Enter your choice : ";
		cin >> choice;
		if (choice < 1 || choice > 4) {
			cout << "ERROR: Valid choices are from 1 to 4\nEnter your choice : ";
		}
	}
	switch (choice) {
	case 1:
		cout << "There are " << a << " occurences of Adenine\n";
		cout << "Enter occurence: ";
		choice = -1;
		while (choice > 0 || choice < a) {
			cin >> choice;
			if (choice > 0 && choice < a) {
				cout << "Occurence " << choice << " of Adenine is at postion " << locationA[choice - 1] << " of the sequence";
			}
			else {
				cout << "ERROR: Valid occurenes are from 1 to " << a << "\nEnter Occurence: ";
			}
		}
		break;
	case 2:
		cout << "There are " << t << " occurences of Thymine\n";
		cout << "Enter occurence: ";
		choice = -1;
		while (choice > 0 || choice < t) {
			cin >> choice;
			if (choice > 0 && choice < t) {
				cout << "Occurence " << choice << " of Thymine is at postion " << locationT[choice - 1] << " of the sequence";
			}
			else {
				cout << "ERROR: Valid occurenes are from 1 to " << t << "\nEnter Occurence: ";
			}
		}
		break;
	case 3:
		cout << "There are " << c << " occurences of Cytosine\n";
		cout << "Enter occurence: ";
		choice = -1;
		while (choice > 0 || choice < c) {
			cin >> choice;
			if (choice > 0 && choice < c) {
				cout << "Occurence " << choice << " of Cytosine is at postion " << locationC[choice - 1] << " of the sequence";
			}
			else {
				cout << "ERROR: Valid occurenes are from 1 to " << c << "\nEnter Occurence: ";
			}
		}
		break;
	case 4:
		cout << "There are " << g << " occurences of Guanine\n";
		cout << "Enter occurence: ";
		choice = -1;
		while (choice > 0 || choice < g) {
			cin >> choice;
			if (choice > 0 && choice < g) {
				cout << "Occurence " << choice << " of Guanine is at postion " << locationG[choice - 1] << " of the sequence";
			}
			else {
				cout << "ERROR: Valid occurenes are from 1 to " << g << "\nEnter Occurence: ";
			}
		}
		break;
	}
}

//output for file and console incase failure in file
void outPutData(ostream& out, double n, int a, int t, int c, int g) {
	out << "DNA sequence analysis :\n" << n << " nucleotides in the sequence\n\nSequence breakdown:\n";
	out << "Adenine: " << a << fixed << setprecision(2) << setw(10) << (a / n * 100) << "%\n";
	out << "Thymine: " << t << fixed << setprecision(2) << setw(10) << (a / n * 100) << "%\n";
	out << "Cytosine: " << c << fixed << setprecision(2) << setw(9) << (c / n * 100) << "%\n";
	out << "Guanine: " << g << fixed << setprecision(2) << setw(10) << (g / n * 100) << "%\n";
	out << endl;
}

//file output and console output if file fails
void outPutDataFile(double n, int a, int t, int c, int g) {
	ofstream fout;
	fout.open(DNACOUNT);
	if (fout) { //checks to see if dnaCount.txt exists
		outPutData(fout, n, a, t, c, g);
		fout.close();
	}
	else {
		cout << "Error Opening " << DNACOUNT << endl;
		outPutData(cout, n, a, t, c, g);
	}
}


//----- Driver Code -------------------------------------------------------------

int main() {
	bool error = false;
	int adenine = 0;
	int thymine = 0;
	int cytosine = 0;
	int guanine = 0;
	char* dna = new char[SIZE_INCREMENT];
	int nucleotides = 0;
	dna = readDataText(dna, nucleotides, adenine, thymine, cytosine, guanine);
	int* locationsA = new int[adenine];
	locationsA = findLocations(dna, locationsA, nucleotides, 'A');
	int* locationsT = new int[thymine];
	locationsT = findLocations(dna, locationsT, nucleotides, 'T');
	int* locationsC = new int[cytosine];
	locationsC = findLocations(dna, locationsC, nucleotides, 'C');
	int* locationsG = new int[guanine];
	locationsG = findLocations(dna, locationsG, nucleotides, 'G');


	outPutDataFile(nucleotides, adenine, thymine, cytosine, guanine);
	outPutData(adenine, locationsA, thymine, locationsT, cytosine, locationsC, guanine, locationsG);
}