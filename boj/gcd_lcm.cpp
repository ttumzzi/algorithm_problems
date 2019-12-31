#include <iostream>
using namespace std;

int gcd(int p, int q) {
    if (q == 0) return p;
    return gcd(q, p % q);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    int a, b;
    cin >> a >> b;
    printf("%d\n", gcd(a, b));

}