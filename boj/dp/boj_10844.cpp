#include <stdio.h>
#define DEVIDING 1000000000

int d[101][10];

int main(){
    int num, sum = 0;
    scanf("%d", &num);

    for(int i = 1 ; i <= 9; i++){
        d[1][i] = 1;
    }
    

    for(int i = 2; i <= num; i++){
        d[i][0] = (d[i-1][1]) % DEVIDING;
        for(int j = 1; j <= 8; j++)
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % DEVIDING;
        d[i][9] = (d[i-1][8]) % DEVIDING;
    }

    for(int i = 0; i <= 9; i++)
        sum = (sum + d[num][i]) % DEVIDING;
    
    printf("%d\n", sum);
}