#include <iostream>
using namespace std;

int a[1000], d[1000];

int main() {
    int n, answer = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    d[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                d[i] = d[j] > d[i] ? d[j] : d[i];
        }
        d[i]++;
        answer = d[i] > answer ? d[i] : answer;
    }

    cout << answer;
}