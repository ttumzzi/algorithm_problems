#include <iostream>
using namespace std;

int main() {
	int N;
	int output = -1;
	cin >> N;

	int max_b = N / 5;

	while (max_b >= 0) {
		if ((N - 5 * max_b) % 3 == 0) {
			output = max_b + ((N - 5 * max_b) / 3);
			break;
		}
		max_b--;
	}

	printf("%d", output);
}