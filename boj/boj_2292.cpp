#include <iostream>
using namespace std;

int main() {
	int n, output, tmp;
	cin >> n;

	if (n <= 2)
		printf("%d", n);
	else {
		output = 3;
		while (true) {
			tmp = 3 * output * output - 9 * output + 8;
			if (tmp > n) {
				printf("%d", output - 1);
				return 0;
			}
			else if (tmp == n) {
				printf("%d", output);
				return 0;
			}
			output++;
		}
	}
}