#include <iostream>
using namespace std;

int main() {
	int t, n, result;
	cin >> t;
	result = t;
	while (t--) {
		cin >> n;
		if (n % 2 == 0 || n == 1)
			result--;
		else {
			for (int i = 1; i < (n >> 1) - 1; i++) {
				if (n % ((i << 1) + 1) == 0) {
					result--;
					break;
				}
				else
					continue;
			}
		}
		if (n == 2)
			result++;
	}
	printf("%d", result);
}