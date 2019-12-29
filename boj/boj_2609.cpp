#include <iostream>
using namespace std;

int main(){
    int a, b, pivot;
    int max = 1, min = 1;
    cin >> a >> b;

    if(a==1){
        printf("%d\n%d\n", a, a*b);
        return 0;
    }else if(b == 1){
        printf("%d\n%d\n", b, a*b);
        return 0;
    }

    if(a >= b) pivot = a;
    else pivot = b;

    for(int i = 2; i <= pivot; i++){
        while(a%i == 0 && b%i == 0){
            max *= i;
            a /= i;
            b /= i;
        }
    }
    min = max * a * b;

    printf("%d\n%d\n", max, min);
    
}