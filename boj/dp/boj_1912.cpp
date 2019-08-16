#include <stdio.h>
#include <algorithm>

int d[100001];
int num[100001];

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        scanf("%d", &num[i]);

    d[0] = num[0];
    d[1] = std::max(num[1], d[0]);
    d[1] = std::max(d[1], d[0]+num[1]);
    for(int i = 2; i < t; i++){
        if(d[i-1] == d[i-2]){
            d[i] = std::max(num[i], d[i-1]);
        }else{
            d[i] = std::max(num[i]+d[i-1], d[i-1]);
        }
    }

    int max = -900000000;
    for(int i = 0; i < t; i++){
        if(d[i] >= max)
            max = d[i];
    }
    
    printf("%d\n", max);

}