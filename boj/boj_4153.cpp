#include <stdio.h>
#include <algorithm>
using namespace std;
int a, b, c, m;

int main() {
	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) return 0;

		m = std::max({ a, b, c });
		if (a * a + b * b + c * c - m * m * 2 == 0)
			printf("right\n");
		else
			printf("wrong\n");

	}
}