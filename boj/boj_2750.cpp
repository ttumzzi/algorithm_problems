#include <iostream>
using namespace std;

int arr[1000];

void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int t, loop = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
		cin >> arr[i];

	for (int i = 1; i < t; i++) {
		for (int j = 0; j < t - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}

	for (int i = 0; i < t; i++)
		printf("%d\n", arr[i]);
}

