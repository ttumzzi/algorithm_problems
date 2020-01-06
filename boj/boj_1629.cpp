#include <iostream>
#include <math.h>
using namespace std;

long long divide(long long a, long long b, long long mod){
    if(b == 1){
        return a % mod;
    }

    long long half = divide(a, b/2, mod);

    if(b % 2 == 0){
        return (half * half) % mod;
    }else{
        return (half * divide(a, b/2 + 1, mod)) % mod;
    }
}

int main(){
    unsigned long long a, b, c, tmp;
    cin >> a >> b >> c;
    printf("%llu\n", divide(a, b, c));
}