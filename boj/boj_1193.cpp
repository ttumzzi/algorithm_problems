#include <iostream>
using namespace std;

int main() {
	int input, a, b, distance, n=1;
	cin >> input;

	while (n * (n + 1) / 2 < input) 
		n++;
	distance = n * (n + 1) / 2 - input;

	a = n;
	b = 1;

	for (int i = 0; i < distance; i++) {
		a--;
		b++;
	}

	if (n%2 == 0)
		printf("%d/%d", a, b);
	else
		printf("%d/%d", b, a);
}