#include <iostream>
using namespace std;
#define mod 1000000000
long long a[101][10] = {
    0,
};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) a[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        a[i][0] = a[i - 1][1];
        for (int j = 1; j <= 8; j++)
            a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % mod;
        a[i][9] = a[i - 1][8];
    }

    long long answer = 0;
    for (int i = 0; i < 10; i++)
        answer = (answer + a[n][i]) % mod;
    cout << answer % mod;
}