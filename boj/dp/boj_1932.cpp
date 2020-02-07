#include <stdio.h>

int triangle[500][500];

int main(){
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        for(int j = 0; j <= i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }

    int max = -1;
    for(int i = 1; i < t; i++){
        for(int j = 0; j <= i; j++){
            for(int k = j-1; k <= j; k++){
                if(triangle[i-1][k] > max)
                    max = triangle[i-1][k];
            }
            triangle[i][j] += max;
            max = -1;
        }
    }

    max = -1;
    for(int i = 0; i < t; i++){
        if(triangle[t-1][i] > max)
            max = triangle[t-1][i];
    }
    printf("%d\n", max);
}

