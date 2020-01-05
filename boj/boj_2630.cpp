#include <iostream>
using namespace std;

int arr[128][128];
int white = 0, blue = 0;

void conquer(int head_v, int head_h, int n){
    int i, j;
    int flag = arr[head_v][head_h];

    if(n == 1){
        flag==0?white++:blue++;
        return;
    }

    for(i = head_v; i< head_v + n; i++){
        for(j = head_h; j < head_h + n; j++){
            if(arr[i][j] != flag){
                //divide
                int half = n/2;
                conquer(head_v, head_h, half);
                conquer(head_v + half, head_h, half);
                conquer(head_v, head_h + half, half);
                conquer(head_v + half, head_h + half, half);
                return;
            }
        }
    }

    flag==0?white++:blue++;
    return;
}

int main(){
    int t, i, j;
    
    cin >> t;

    for(i = 0; i < t; i++){
        for(j = 0; j < t; j++){
            cin >> arr[i][j];
        }
    }

    conquer(0, 0, t);

    printf("%d\n%d\n", white, blue);
    
}