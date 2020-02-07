#include <stdio.h>

long long d[1001][10];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        d[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 9; j++){
            d[i][j] = (d[i][j-1] + d[i-1][j]) % 10007;
        }
    }

    int sum = 0;
    for(int i = 0; i <= 10; i++)
        sum = sum + d[n][i];

    printf("%d\n", sum % 10007);
}