#include <iostream>
using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    tmp = n;

    if(n == 1) return 0;

    for(int i = 2; i <= n; i++){
        while(tmp % i == 0){
            tmp /= i;
            printf("%d\n", i);
        }
    }
}