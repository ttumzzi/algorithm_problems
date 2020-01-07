#include <iostream>
using namespace std;

int main(){
    int n, i, j, k, arr[5][5], mod = 1000;
    long long tmp_num;
    long long b, res[5][5], tmp[5][5], x[5][5], tmp2[5][5];
    cin >> n >> b;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            cin >> arr[i][j];
            x[i][j] = arr[i][j];
            i==j?res[i][j] = 1:res[i][j] = 0;
        }

    while(b > 0){
        if(b % 2 == 1){
            for(i = 0; i < n; i++){
                for(j = 0; j < n; j++)
                    tmp[i][j] = res[i][j];
            }
            for(i = 0; i < n; i ++){
                for(j = 0; j < n; j++){
                    tmp_num = 0;
                    for(k = 0; k < n; k++){
                        tmp_num += (tmp[i][k] * x[k][j]) % mod;
                    }
                    res[i][j] = tmp_num % mod;
                }
            }
        }

        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                tmp[i][j] = x[i][j];
                tmp2[i][j] = x[i][j];
            }
        }

        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j++){
                tmp_num = 0;
                for(k = 0; k < n; k++){
                    tmp_num += (tmp[i][k] * tmp2[k][j]) % mod;
                }
                x[i][j] = tmp_num % mod;
            }
        } 

        b >>= 1;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%d ", res[i][j] % mod);
        printf("\n");
    }
    
}