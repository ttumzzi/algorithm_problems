#include <iostream>
using namespace std;

long long dividing2(long long n){
    long long result = 0;
    for(long long i = 2; i <= n; i*=2){
        result += n/i;
    }
    return result;
}

long long dividing5(long long n){
    long long result = 0;
    for(long long i = 5; i <= n; i*=5){
        result += n/i;
    }
    return result;
}

int main(){
    long long n, m;
    cin >> n >> m;

    long long two = dividing2(n) - dividing2(m) - dividing2(n-m);
    long long five = dividing5(n) - dividing5(m) - dividing5(n-m);
    long long result = two>five?five:two;

    cout << result;
}