#include <stdio.h>

int d[10001];
int c[101];

int main(){
    int t, val;
    scanf("%d %d", &t, &val);
    
    for(int i = 1; i <= t; i++){
        scanf("%d", &c[i]);
    }

    d[0] = 1;

    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= val; j++){
            if(j >= c[i])
                d[j] += d[j-c[i]];
        }
    }

    printf("%d\n", d[val]);


    
}