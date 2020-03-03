#include <iostream>
using namespace std;
#define mod 1000000000

int d[101][10];

int main() {
    int n, answer = 0;
    cin >> n;

    for (int i = 1; i < 10; i++) d[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                d[i][j] = d[i - 1][1];
            else if (j == 9)
                d[i][j] = d[i - 1][8];
            else
                d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
        }

    for (int i = 0; i < 10; i++) answer = (answer + d[n][i]) % mod;
    cout << answer;
}