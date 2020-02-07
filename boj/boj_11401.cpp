#include <iostream>
using namespace std;

long long mod = 1000000007;
long long factorial[4000001], inv[4000001];

long long pow(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res *= x;
        
        x *= x;
        y >>= 1;
    }
    return res;
}

int main(){
    long long n, k, i, res;

    factorial[0] = 1;
    for(i=1; i<=4000000; i++)
        factorial[i] = (factorial[i-1] * i)%mod;
    
    inv[4000000] = pow(factorial[4000000], mod - 2);
    for (i = 4000000 - 1; i >= 0; i--) 
        inv[i] = (inv[i + 1] * (i + 1)) % mod;

    cin >> n >> k;
    
    if(n==k){
        printf("1\n");
        return 0;
    }

    res = (inv[n-k] * inv[k])%mod;
    res = (res * factorial[n])%mod;
    printf("%lld\n", res);
}