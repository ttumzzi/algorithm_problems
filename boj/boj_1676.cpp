#include <iostream>
using namespace std;

int main(){
    int n;
    int result = 0;
    cin >> n;

    for(int  i = 5; i <= n; i += 5){
        if((i<<4) % 1000 == 0) result += 3;
        else if((i<<4) % 100 == 0) result += 2;
        else result += 1;
    }

    printf("%d\n", result);
}