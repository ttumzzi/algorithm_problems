#include <iostream>
using namespace std;

int main(){
    int n, m, k, i, j, l, tmp = 0;
    int a[100][100], b[100][100];

    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> a[i][j];
        
    
    cin >> m >> k;
    for(i = 0; i < m; i++)
        for(j = 0; j < k; j++)
            cin >> b[i][j];
    

    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            tmp = 0;
            for(l = 0; l < m; l++){
                tmp += a[i][l] * b[l][j];
            }
            printf("%d ", tmp);
        }
        printf("\n");
    }
}