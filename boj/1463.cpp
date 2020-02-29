#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    v[1] = 0, v[2] = 1, v[3] = 1;
    for (int i = 4; i <= n; i++) {
        int min_elem = v[i - 1] + 1;
        if (i % 2 == 0) min_elem = min(min_elem, v[i / 2] + 1);
        if (i % 3 == 0) min_elem = min(min_elem, v[i / 3] + 1);
        v[i] = min_elem;
    }
    cout << v[n] << endl;
}