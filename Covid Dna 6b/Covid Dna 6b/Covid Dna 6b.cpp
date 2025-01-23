/*
FILe OUTPUT/TESTING RESULTS:
DNA sequence analysis :
29782 nucleotides in the sequence

Sequence breakdown:
Adenine: 8892     29.86%
Thymine: 9581     32.17%
Cytosine: 5462    18.34%
Guanine: 5847     19.63%
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

//----- Functions ---------------------------------------------------------------

bool readData(double& n, int& a, int& t, int& c, int& g) {
	ifstream fin;
	fin.open(SEQUENCE);
	if (fin) {//checks to see if dnaSequence.txt exists
		char value;
		while (fin.get(value)) {
			n++;
			if (value == 'A') {
				a++;
			}
			else if (value == 'T') {
				t++;
			}
			else if (value == 'C') {
				c++;
			}
			else if (value == 'G') {
				g++;
			}
			else {
				n--; //if anything but ATCG is read, it nullifies the nucleotides++
			}
		}
		fin.close();
		return true;
	}
	else {
		cout << "Error Opening dnaSequence.txt" << endl;
		return false;
	}
}

void outPutData(ostream& out, double n, int a, int t, int c, int g) {
	out << "DNA sequence analysis :\n" << n << " nucleotides in the sequence\n\nSequence breakdown:\n";
	out << "Adenine: " << a << fixed << setprecision(2) << setw(10) << (a / n * 100) << "%\n";
	out << "Thymine: " << t << fixed << setprecision(2) << setw(10) << (a / n * 100) << "%\n";
	out << "Cytosine: " << c << fixed << setprecision(2) << setw(9) << (c / n * 100) << "%\n";
	out << "Guanine: " << g << fixed << setprecision(2) << setw(10) << (g / n * 100) << "%\n";
}

void outPutDataFile(double n, int a, int t, int c, int g) {
	ofstream fout;
	fout.open(DNACOUNT);
	if (fout) { //checks to see if dnaCount.txt exists
		outPutData(fout, n, a, t, c, g);
		fout.close();
	}
	else {
		cout << "Error Opening dnaCount.txt" << endl;
	}
}



//----- Driver Code -------------------------------------------------------------

int main() {
	double nucleotides = 0;
	int adenine = 0;
	int thymine = 0;
	int cytosine = 0;
	int guanine = 0;
	bool read = readData(nucleotides, adenine, thymine, cytosine, guanine);
	outPutData(cout, nucleotides, adenine, thymine, cytosine, guanine);
	outPutDataFile(nucleotides, adenine, thymine, cytosine, guanine);
}