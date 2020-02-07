#include <stdio.h>
#include <algorithm>

int d[100001];
int num[100001];

int main(){
    int t, max;
    bool selected_before = false;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        scanf("%d", &num[i]);

    d[0] = num[0];
    max = d[0];
    for(int i = 1; i < t; i++){
        d[i] = std::max(num[i], d[i-1]+num[i]);
        if(d[i] > max)
            max = d[i];
    }

    printf("%d\n", max);
}