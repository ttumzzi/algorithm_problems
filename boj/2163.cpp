#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int d[301][301];

int main() {
    int n, m, l, s;
    cin >> n >> m;
    l = max(n, m), s = min(n, m);
    d[1][1] = 1;
    for (int i = 2; i <= l; i++) d[1][i] = i - 1;
    for (int i = 2; i <= s; i++) {
        for (int j = i; j <= l; j++) {
            d[i][j] = 9999999;
            for (int x = 1; x <= sqrt(i); x++)
                d[i][j] = min(d[min(x, j)][max(x, j)] + d[min(i - x, j)][max(i - x, j)] + 1, d[i][j]);

            for (int x = 1; x <= sqrt(j); x++)
                d[i][j] = min(d[min(x, i)][max(x, i)] + d[min(j - x, i)][max(j - x, i)] + 1, d[i][j]);
        }
    }
    cout << d[s][l];
}