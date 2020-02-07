#include <stdio.h>

int arr[31];

int main(){
    int n;
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 3;
    arr[3] = 0;

    scanf("%d", &n);

    for(int i = 4; i <= n; i++){
        if(i % 2 == 0){
        arr[i] = arr[i-2] * 3;
        int k = i - 4;
        for(int j = 0 ; j <= k; j++)
            arr[i] += arr[j] << 1;
        }
    }

    printf("%d\n", arr[n]);
}