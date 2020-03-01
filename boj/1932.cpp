#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, sum;
};
int a[501][501], d[501][501];

int main() {
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
            if (i == 0)
                d[i][j] = a[i][j];
            else if (j == 0)
                d[i][j] = d[i - 1][j] + a[i][j];
            else if (j == i)
                d[i][j] = d[i - 1][j - 1] + a[i][j];
            else
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
        }

    for (int i = 0; i < n; i++)
        answer = max(answer, d[n - 1][i]);

    cout << answer;
}