#include <algorithm>
#include <iostream>
using namespace std;

int a[1001], d[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    d[1] = a[1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            d[i] = max(d[i], d[i - j] + a[j]);

    cout << d[n];
}