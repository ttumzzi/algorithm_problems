#include <iostream>
using namespace std;

int arr[64][64];

void conquer(int head_v, int head_h, int n){
    int i,j;
    int flag = arr[head_v][head_h];

    if(n == 1){
        printf("%d", flag);
        return;
    }

    for(i = head_v; i < head_v + n; i++){
        for(j = head_h; j < head_h + n; j++){
           if(flag != arr[i][j]){
                int half = n >> 1;
                printf("(");
                conquer(head_v, head_h, half);
                conquer(head_v, head_h + half, half);
                conquer(head_v + half, head_h, half);
                conquer(head_v + half, head_h + half, half);
                printf(")");
                return;
           }
        }
    }
    printf("%d", flag);
    return;
}

int main(){
    int n, i, j;
    string tmp;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tmp;
        for(j = 0; j < n; j++)
            tmp[j]=='0'?arr[i][j]=0:arr[i][j]=1;
    }
    conquer(0, 0, n);
}