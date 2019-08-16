#include <stdio.h>
#define DEVIDING_VAL 1000000007
long long int arr[1000001];

int main(){
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 7;
    arr[3] = 22;

    int t;
    scanf("%d", &t);

    for(int i = 4; i <= t; i++){
        arr[i] = (3 * arr[i - 1]) % DEVIDING_VAL;
        arr[i] += arr[i - 2] % DEVIDING_VAL;
        arr[i] -= arr[i - 3] % DEVIDING_VAL;
    }

    printf("%lld\n", arr[t]);

    // for(int i = 0 ; i <= t; i++)
    //     printf("%lld\n", arr[i]);
    return 0;
}