#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int abs(int num){
    if(num >= 0) return num;
    else return num*(-1);
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int i;
    int n, tmp, g;
    int a[101];
    vector <int> result;

    cin >> n; 
    for(i = 0; i < n; i++){
        cin >> tmp;
        a[i] = tmp;
    }
    g = abs(a[1] - a[0]);
    for(i = 1; i < n-1; i++){
        g = gcd(g, abs(a[i+1] - a[i]));
    }

    for(i = 2; i*i <= g; i++){
        if(g % i == 0){
            result.push_back(i);
            result.push_back(g/i);
        }
    }
    result.push_back(g);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    for(i = 0 ; i < result.size(); i++){
        printf("%d ", result[i]);
    }
    printf("\n");
}