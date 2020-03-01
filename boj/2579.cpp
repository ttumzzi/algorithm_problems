#include <algorithm>
#include <iostream>
using namespace std;

int a[301], d[301];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1)
            d[i] = a[i];
        else if (i == 2)
            d[i] = a[i] + a[i - 1];
        else
            d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
    }

    cout << d[n];
}