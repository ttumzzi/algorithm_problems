#include <iostream>
using namespace std;

int main() {
	char b[8][8] = { {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'} };
	char w[8][8] = { {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
					 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
					 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'} };

	int n, m;
	char arr[51][51];
	cin >> n >> m;
	int min = m * n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
		
	int cnt_b = 0;
	int cnt_w = 0;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			cnt_b = 0; cnt_w = 0;
			for (int l = i; l < i + 8; l++) {
				for (int k = j; k < j + 8; k++) {
					if (arr[l][k] != b[l - i][k - j]) cnt_b++;
					if (arr[l][k] != w[l - i][k - j]) cnt_w++;
				}
			}
			if (cnt_b < min) min = cnt_b;
			if (cnt_w < min) min = cnt_w;
		}
	}

	printf("%d", min);
}