#include <iostream>
using namespace std;

const int MOD = 10007;
int a[1001][1001];

int main(){
    int n, k;
    int i, j;

    
    cin >> n >> k;

    if(n-k < k) k = n - k;

    for(i = 0; i <= n; i++){
        a[i][1] = i;
        a[i][0] = 1;
        a[i][i] = 1;
    }

    if(k <= 1) {
        printf("%d\n", a[n][k]);
        return 0;
    }

    for(i = 2; i <= n; i++){
        for(j = 2; j < i; j++){
            a[i][j] = (a[i-1][j-1] + a[i-1][j]) % MOD;
            if(i == n && j == k){
                printf("%d\n", a[i][j]);
                return 0;
            }
        }
    }

}