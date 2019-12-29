#include <iostream>
using namespace std;

/* 소수점 분수로 바꾸기 */

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int a[100];
    int n, tmp, i;
    int under = 1, upper = 1;

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tmp;
        a[i] = tmp;
    }

    for(i = 0; i < n - 1; i++){
        tmp = gcd(a[i] * upper, a[i+1] * under);
        upper = a[i] * upper / tmp;
        under = a[i+1] * under / tmp;
        printf("%d/%d\n", upper, under);
    }
}