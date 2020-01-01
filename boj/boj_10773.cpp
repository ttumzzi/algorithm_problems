#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;
    int t,n, sum = 0;
    cin >> t;

    while(t--){
        cin >> n;
        if(n == 0){
            v.pop_back();
        }else{
            v.push_back(n);
        }
    }

    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    } 
    cout << sum;
}