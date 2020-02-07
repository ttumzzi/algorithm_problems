#include <stdio.h>

long long int d[91];

int main(){
    d[0] = 0;
    d[1] = 1;

    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + d[i-2];
    }
    printf("%lld\n", d[n]);
}