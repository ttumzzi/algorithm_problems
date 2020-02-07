#include <iostream>

int d[12];

int main(){
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;

    for(int i = 3; i <= 11; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}