#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp;
    int result = 0;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        result += v.at(i) * (n - i);
    }
    printf("%d\n", result);
}