#include <iostream>
using namespace std;
#define MAX_VAL 91

long long arr[MAX_VAL];

int main(){
    arr[0] = 0;
    arr[1] = 1;
    int t;
    cin >> t;

    if(t >= 2){
        for(int i = 2; i <= t; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
    }
    
    cout << arr[t] << "\n";
}