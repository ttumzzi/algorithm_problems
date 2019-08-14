#include <iostream>
using namespace std;

int main(){
    int t, a = 0, b = 1, c;

    cin >> t;

    for(int i = 1; i <= t; i++){
        c = (a + b) % 15746;
        a = b;
        b = c;
    }

    printf("%d\n", c);
}