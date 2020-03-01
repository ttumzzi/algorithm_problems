#include <algorithm>
#include <iostream>
using namespace std;

int a[100001];

int main() {
    int n, tmp, d, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    d = a[1], answer = a[1];

    for (int i = 2; i <= n; i++) {
        d = max(0, d) + a[i];
        answer = max(d, answer);
    }

    cout << answer;
}