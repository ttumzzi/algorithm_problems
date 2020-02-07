#include <stdio.h>

long a[500][500];
int d[500][500];

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        if(a[i][0] < a[i-1][0] || i == 0)
            d[i][0] = 1;
    }

    for(int i = 0; i < n; i++){
        if(a[0][i] < a[0][i-1])
            d[0][i] = 1;
    }


    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(a[i][j-1] > a[i][j] && d[i][j-1] != 0)
                d[i][j] += d[i][j-1];
            if(a[i-1][j] > a[i][j] && d[i-1][j] != 0)
                d[i][j] += d[i-1][j];
            if(a[i-1][j] < a[i][j] && d[i-1][j] != 0)
                d[i-1][j] += d[i][j];
            if(a[i][j-1] < a[i][j] && d[i-1][j] != 0)
                d[i][j-1] += d[i][j];
        }
    }

    printf("%ld\n", d[m-1][n-1]);



}
