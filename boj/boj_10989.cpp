#include <iostream>
using namespace std;
#define MAX_NUM 10001
/* counting Á¤·Ä */

int cnt[MAX_NUM] = { 0, };

int main() {
	int t, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;
		cnt[num]++;
	}
	for (int i = 1 , num = 0; num < t; i++) {
		while (cnt[i]--) {
			printf("%d\n", i);
			num++;
		}
	}
}
