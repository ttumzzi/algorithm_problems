#include <stdio.h>
#include <algorithm>

int min[1001][3];

int main(){
    int t, r, g, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &r, &g, &b);
        min[i][0] = r;
        min[i][1] = g;
        min[i][2] = b;
    }

    for(int i = 1; i < t; i++){
        min[i][0] += std::min(min[i-1][1], min[i-1][2]);
        min[i][1] += std::min(min[i-1][0], min[i-1][2]);
        min[i][2] += std::min(min[i-1][0], min[i-1][1]);
    }

    printf("%d\n", std::min({min[t-1][0], min[t-1][1], min[t-1][2]}));


}