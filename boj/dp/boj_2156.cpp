#include <stdio.h>
#include <algorithm>

int d[10001];
int wine[10001];

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        scanf("%d", &wine[i]);
    
    d[0] = wine[0];
    d[1] = std::max(wine[0] + wine[1], d[0]);
    d[2] = std::max({wine[1] + wine[2], d[0] + wine[2], d[1]});

    for(int i = 3; i < t; i++){
        d[i] = std::max({d[i-3] + wine[i-1] + wine[i], d[i-2] + wine[i], d[i-1]});
    }
    int max = -1;
    for(int i = 0; i < t; i++)
        if(d[i] >= max)
            max = d[i];

    printf("%d\n", max);
}