#include <stdio.h>

int main() {
	int n, p_cnt;
	bool is_prime = true;
	
	while (true) {
		scanf_s("%d", &n);
		if (n == 0) return 0;
		
		p_cnt = 0;
		for (int i = n + 1; i <= (n << 1); i++) {
			is_prime = true;
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0) {
					is_prime = false;
					break;
				}
			}
			if (is_prime && i != 1) p_cnt++;
		}
		printf("%d\n", p_cnt);
	}
}