#include <cstdio>
using namespace std;

int main() {
	int a, b, t = 3, output_a = 0, output_b = 0;

	while (t--) {
		scanf_s("%d %d", &a, &b);
		output_a ^= a;
		output_b ^= b;
	}

	/*
	scanf("%d %d", &a, &b);
	output_a = a; output_b = b;

	scanf("%d %d", &a, &b);

	if (output_a == a) {
		output_a = 0;
		output_b += b;
		scanf("%d %d", &a, &b);
		output_a += a;
		output_b -= b;
	}
	else if (output_b == b) {
		output_b = 0;
		output_a += a;
		scanf("%d %d", &a, &b);
		output_b += b;
		output_a -= a;
	}
	else {
		output_a += a;
		output_b += b;
		scanf("%d %d", &a, &b);
		output_b -= b;
		output_a -= a;

	}
	*/

	printf("%d %d", output_a, output_b);

}