#include <iostream>
#include <string>
using namespace std;

void hanoi(int number, int start, int target, int sub) {
	if (number == 1) {
		cout << number << "->" << "[" << start << "," << target << "]" << endl;
		return;
	}

	hanoi(number - 1, start, sub, target);
	cout << number << "->" << "[" << start << "," << target << "]" << endl;
	hanoi(number - 1, sub, target, start);
}

int main() {
	int n;
	cout << "number of rings: ";
	cin >> n;

	hanoi(n, 1, 2, 3);
}	