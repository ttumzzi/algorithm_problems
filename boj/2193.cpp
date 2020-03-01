#include <iostream>
using namespace std;

long long d[91][2];

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 1 << endl;
        return 0;
    }
    long long a = 1, b = 0, c;
    for (int i = 3; i <= n; i++) {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i][0] + d[i][1] << endl;
    }
}