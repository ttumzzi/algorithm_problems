#include <iostream>
using namespace std;
#define MAXIMUM 1000000
int tmp[MAXIMUM];
int arr[MAXIMUM];

void merge(int head, int mid, int tail) {
	int p1 = head;
	int p2 = mid + 1;
	int p = head;
	while (p1 <= mid && p2 <= tail) {
		if (arr[p1] < arr[p2])
			tmp[p++] = arr[p1++];
		else
			tmp[p++] = arr[p2++];
	}

	if (p1 > mid) {
		for (int i = p2; i <= tail; i++)
			tmp[p++] = arr[i];
	}
	else {
		for (int i = p1; i <= mid; i++)
			tmp[p++] = arr[i];
	}

	for (int i = head; i <= tail; i++)
		arr[i] = tmp[i];

	return;
}

void partition(int head, int tail) {
	if (head < tail) {
		int mid = (head + tail) >> 1;
		partition(head, mid);
		partition(mid + 1, tail);

		merge(head, mid, tail);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> arr[i];

	partition(0, t - 1);

	for (int i = 0; i < t; i++)
		printf("%d\n", arr[i]);

}