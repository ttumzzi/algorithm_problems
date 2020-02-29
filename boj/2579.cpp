#include <algorithm>
#include <iostream>
using namespace std;

int a[301], d[301];

int main() {
    int stair_num, n;
    cin >> stair_num;
    for (int i = 0; i < stair_num; i++)
        cin >> a[i + 1];

    d[0] = 0, d[1] = a[1], d[2] = a[1] + a[2];
    for (int i = 3; i <= stair_num; i++)
        d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);

    cout << d[stair_num] << endl;
}