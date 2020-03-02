#include <iostream>
using namespace std;

int main() {
    int n, a = 1, b = 1, c = 2;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        c = (2 * a + b) % 10007;
        a = b, b = c;
    }
    cout << (n == 1 ? 1 : c);
}