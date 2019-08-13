#include <iostream>
using namespace std;

int main() {
	int m, n, minimum = 0, total = 0;
	bool first_prime = true, is_prime = true;

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (i == 1) continue;
		if ((i % 2) != 0 || i == 2) {
			for (int j = 2; j * j <= i; j++) {
				is_prime = true;
				if (i % j == 0) {
					is_prime = false; break;
				}
			}
			
			if (is_prime) {
				total += i;
				if (first_prime) {
					minimum = i;
					first_prime = false;
				}
			}
		}
	}

	if (!first_prime)
		printf("%d\n%d", total, minimum);
	else
		printf("-1");


}