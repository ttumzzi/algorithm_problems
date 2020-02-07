#include <stdio.h>

int d[30][30];

int main(){
    for(int i = 1; i < 30; i++){
        d[i][i] = 1;
        d[i][1] = i;
    }
    
    for(int i = 2; i < 30; i++){
        for(int j = 2; j < i; j++){
            d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    }

    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d\n", d[m][n]);
    }
}