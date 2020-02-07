#include <stdio.h>

int d[1000];
int a[1000];

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
        scanf("%d", &a[i]);

    d[0] = 1;
    for(int i = 1; i < t; i++){
        d[i] = 1;
        for(int j = 0; j <= i; j++){
            if(a[j] < a[i] && d[j] >= d[i])
                d[i] = d[j] + 1;
        }
    }

    int max = -1;
    for(int i = 0; i < t; i++){
        if(d[i] >= max)
            max = d[i];
    }

    printf("%d\n", max);
}