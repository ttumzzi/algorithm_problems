#include <iostream>
using namespace std;

long long arr[101];

int main(){
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    for(int i = 4; i <= 100; i++)
        arr[i] = arr[i-2] + arr[i-3];

    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
}