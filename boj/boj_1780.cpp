#include <iostream>
using namespace std;

int arr[2187][2187];
int neg=0, zero=0, pos=0;

void conquer(int head_v, int head_h, int n){
    int i, j;
    int flag = arr[head_v][head_h];
    if(n==1){
        flag==-1?neg++:(flag==0?zero++:pos++);
        return;
    }
    for(i = head_v; i < head_v + n; i++){
        for(j = head_h; j < head_h + n; j++){
            if(flag != arr[i][j]){
                int one_third = n/3;
                int two_third = (n/3) << 1;
                conquer(head_v, head_h, one_third);
                conquer(head_v, head_h + one_third, one_third);
                conquer(head_v, head_h + two_third, one_third);
                conquer(head_v + one_third, head_h, one_third);
                conquer(head_v + one_third, head_h + one_third, one_third);
                conquer(head_v + one_third, head_h + two_third, one_third);
                conquer(head_v + two_third, head_h, one_third);
                conquer(head_v + two_third, head_h + one_third, one_third);
                conquer(head_v + two_third, head_h + two_third, one_third);
                return;
            }
        }
    }

    flag==-1?neg++:(flag==0?zero++:pos++);
    return;
}

int main(){
    int n, i, j;
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    conquer(0, 0, n);
    printf("%d\n%d\n%d\n", neg, zero, pos);

}