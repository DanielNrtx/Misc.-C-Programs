#include <iostream>
using namespace std;

int main() {
	int num = 0;
	while (num >= 0) {
		if (num < 2147400000) {
			num += 100000;
		}
		else if (num < 2147483600) {
			num += 10;
		}
		else {
			num++;
		}
		cout << num << "\n";
	}
	return 0;
}
//2147483647