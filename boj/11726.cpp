#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3;
    for (int i = 4; i <= n; i++) {
        a = b, b = c;
        c = (a + b) % 10007;
    }
    cout << (n <= 3 ? n : c);
}