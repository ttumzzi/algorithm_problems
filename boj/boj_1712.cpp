#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	int bp_int = 0;

	if (b >= c)
		bp_int = -1;
	else {
		bp_int = a / (c - b);
		bp_int++;
	}

	printf("%d", bp_int);
}