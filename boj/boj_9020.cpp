#include <stdio.h>

int main() {
	int t, n, p_a, p_b;
	bool a, b;

	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		p_a = n >> 1;
		p_b = n >> 1;
		while (p_a > 0) {
			if (p_a % 2 != 0 || p_a == 2) {
				a = true; b = true;
				for (int i = 2; i * i <= p_a; i++) {
					if (p_a % i == 0) {
						a = false;
						break;
					}
				}
				if (a) {
					for (int j = 2; j * j <= p_b; j++) {
						if (p_b % j == 0) {
							b = false;
							break;
						}
					}
					if (b) {
						printf("%d %d\n", p_a, p_b);
						break;
					}
				}
				p_a -= 2;
				p_b += 2;
			}
			else { p_a--; p_b++; }
		}
	}
}