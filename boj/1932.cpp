#include <algorithm>
#include <iostream>
using namespace std;

int a[500][500], d[500][500];
int n;

int solve() {
    int answer = 0;
    d[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                d[i][j] += d[i - 1][j];
            else if (j == i)
                d[i][j] += d[i - 1][j - 1];
            else
                d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
        }

    for (int i = 0; i < n; i++) answer = max(answer, d[n - 1][i]);
    return answer;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }

    cout << solve();
}