#include <iostream>
using namespace std;

int d[41][2];

int main() {
    d[0][0] = 1, d[0][1] = 0;
    d[1][0] = 0, d[1][1] = 1;
    for (int i = 2; i <= 40; i++) {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }

    int t, n;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        printf("%d %d\n", d[n][0], d[n][1]);
    }
}