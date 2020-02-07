#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t, m, n, x, y, num_to_check, idx;
	bool answer_exist;
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		answer_exist = false;
		num_to_check = floor((m * n - x) / m);
		if (num_to_check == 0) {
			printf("1\n");
			continue;
		}
		for (int i = 0; i < num_to_check; i++) {
			idx = m * i + x;
			if (idx % n == y) {
				printf("%d\n", idx);
				answer_exist = true;
				break;
			}
			else if (idx % n == 0 && y == n) {
				printf("%d\n", idx);
				answer_exist = true;
				break;
			}
		}
		if(!answer_exist)
			printf("-1");
	}
}