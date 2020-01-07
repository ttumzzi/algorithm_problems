#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i, j, k;
    long long n, tmp_num, mod=1000000, tmp[2][2]={1,0,0,1}, tmp2[2][2]={1,0,0,1}, res[2][2]={1,0,0,1}, x[2][2]={1,1,1,0};

    cin >> n;

    while(n > 0){
        if(n % 2){
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    tmp[i][j] = res[i][j];
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    tmp_num = 0;
                    for(k=0;k<2;k++){
                        tmp_num += (tmp[i][k] * x[k][j]) % mod;
                    }
                    res[i][j] = tmp_num % mod;
                }
            }
        }
        for(i=0;i<2;i++)
            for(j=0;j<2;j++){
                tmp[i][j] = x[i][j];
                tmp2[i][j] = x[i][j];
            }
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                tmp_num = 0;
                for(k=0;k<2;k++){
                    tmp_num += (tmp[i][k] * tmp2[k][j]) % mod;
                }
                x[i][j] = tmp_num % mod;
            }
        }

        n >>= 1;
    }

    printf("%d\n", (res[1][0]) % mod);


}