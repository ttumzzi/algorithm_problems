#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main() {
	int input, output;
	cin >> input;
	output = factorial(input);
	printf("%d", output);
}