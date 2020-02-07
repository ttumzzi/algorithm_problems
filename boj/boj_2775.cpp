#include <iostream>
using namespace std;

int main() {
	int** arr;
	int t, k, n;
	cin >> t;
	while (t--) {
		cin >> k >> n;
		arr = new int*[k + 1];
		for (int i = 0; i < k + 1; i++)
			arr[i] = new int[n];

		for (int i = 0; i < k + 1; i++) {
			for (int j = 0; j < n; j++) {
				if (j == 0) arr[i][j] = 1;
				else if (i == 0) arr[i][j] = j + 1;
				else arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
		printf("%d\n", arr[k][n - 1]);
		delete[] arr;
	}
}