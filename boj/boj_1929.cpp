#include <iostream>
using namespace std;

int main() {
	int m, n;
	bool p;
	
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (i == 1) continue;
		if (i % 2 != 0 || i == 2) {
			p = true;
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0) {
					p = false;
					break;
				}
			}
			if (p)
				printf("%d\n", i);
		}
	}
}