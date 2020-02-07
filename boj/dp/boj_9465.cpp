#include <stdio.h>
#include <algorithm>

int* d[2];
int* a[2];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        int max_val = -1;
        scanf("%d", &n);
        d[0] = new int[n];
        d[1] = new int[n];
        a[0] = new int[n];
        a[1] = new int[n];

        for(int i = 0; i < n; i++){
            scanf("%d", &a[0][i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &a[1][i]);
        }

        d[0][0] = a[0][0];
        d[1][0] = a[1][0];

        d[0][1] = d[1][0] + a[0][1];
        d[1][1] = d[0][0] + a[1][1];

        for(int i = 2; i < n; i++){
            d[0][i] = std::max({d[1][i-1], d[0][i-2], d[1][i-2]}) + a[0][i];
            d[1][i] = std::max({d[0][i-1], d[0][i-2], d[1][i-2]}) + a[1][i];
            if(d[0][i] > max_val) max_val = d[0][i];
            if(d[1][i] > max_val) max_val = d[1][i];
        }
        printf("%d\n", max_val);
    }
    
}