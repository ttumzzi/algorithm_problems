#include <stdio.h>

int main() {
	int t, max, output = 0;
	int n[101];

	scanf_s("%d %d", &t, &max);
	for (int i = 0; i < t; i++)
		scanf_s("%d", &n[i]);

	for (int i = 0; i < t - 2; i++)
		for (int j = i + 1; j < t - 1; j++)
			for (int k = j + 1; k < t; k++) {
				int sum = n[i] + n[j] + n[k];
				if (sum > output && sum <= max)
					output = sum;
			}

	printf("%d", output);
}