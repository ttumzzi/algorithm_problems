#include <iostream>
#include <math.h>
using namespace std;
#define MAX_NUM 500000

int tmp[MAX_NUM];
int cnt[8001];


void merge(int*arr, int head, int mid, int tail) {
	int p1 = head;
	int p2 = mid + 1;
	int p = head;

	while (p1 <= mid && p2 <= tail) {
		if (arr[p1] > arr[p2])
			tmp[p++] = arr[p2++];
		else if (p1 < p2)
			tmp[p++] = arr[p1++];
	}

	if (p1 <= mid) {
		for (int i = p1; i <= mid; i++) {
			tmp[p++] = arr[i];
		}
	}
	if (p2 <= tail) {
		for (int i = p2; i <= tail; i++) {
			tmp[p++] = arr[i];
		}
	}

	for (int i = head; i <= tail; i++) {
		arr[i] = tmp[i];
	}

}

void partition(int* arr, int head, int tail) {
	if (head >= tail)
		return;
	int mid = (head + tail) >> 1;
	partition(arr, head, mid);
	partition(arr, mid + 1, tail);
	merge(arr, head, mid, tail);
}

int main() {
	int t, sum = 0;
	int max_mode_cnt = 0, mode_cnt = 0, mode_result = 0;
	int* arr;
	cin >> t;
	arr = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
		if (arr[i] < 0) {
			cnt[-1 * arr[i] + 4000]++;
			if (cnt[-1 * arr[i] + 4000] > max_mode_cnt)
				max_mode_cnt = cnt[-1 * arr[i] + 4000];
		}
		else {
			cnt[arr[i]]++;
			if (cnt[arr[i]] > max_mode_cnt) {
				max_mode_cnt = cnt[arr[i]];
			}
		}
		
		sum += arr[i];
	}

	/*Æò±Õ*/
	double avg = double(sum) / double(t);
	printf("%0.0lf\n", avg);

	partition(arr, 0, t - 1);

	/*Áß¾Ó°ª*/
	printf("%d\n", arr[(t - 1) / 2]);

	/*ÃÖºó°ª*/
	for (int i = 8000; i > 4000; i--) {
		if (cnt[i] == max_mode_cnt) {
			mode_cnt++;
			mode_result = (i-4000) * (-1);
			printf("%d======\n", mode_result);
		}
		if (mode_cnt == 2) {
			break;
		}
	}

	if (max_mode_cnt < 2) {
		for (int i = 0; i < 4001; i++) {
			if (cnt[i] == max_mode_cnt) {
				mode_cnt++;
				mode_result = i;
			}
			if (mode_cnt == 2) {
				break;
			}
		}
	}

	printf("%d\n", mode_result);


	/*ÃÖ´ëÃÖ¼Ò Â÷ÀÌ*/
	printf("%d\n", arr[t - 1] - arr[0]);




}