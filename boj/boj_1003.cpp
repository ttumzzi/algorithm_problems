#include <iostream>
using namespace std;
#define MAX_VAL 41

int arr[MAX_VAL][2];

int main(){
    arr[0][0] = 1; arr[0][1] = 0;
    arr[1][0] = 0; arr[1][1] = 1;

    int t, n;
    cin >> t;
    for(int i = 2; i <= 40; i ++){
            arr[i][0] = arr[i-1][0] + arr[i-2][0];
            arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }

    while(t--){
        cin >> n;
        printf("%d %d\n", arr[n][0], arr[n][1]);
    }

}