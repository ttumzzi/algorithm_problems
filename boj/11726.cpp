#include <iostream>
using namespace std;
#define mod 10007

int d[1001];

// 더 효율적인 코드로 만들어보기

int main() {
    d[1] = 1, d[2] = 2;
    for (int i = 3; i <= 1000; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    int n;
    cin >> n;
    cout << d[n] % mod << endl;
}