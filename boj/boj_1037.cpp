#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num, tmp;
    vector <int> v;

    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    
    if(num%2 == 0){
        printf("%d\n", v.at(0)*v.at(num-1));
    }else{
        printf("%d\n", v.at(num/2)*v.at(num/2));
    }
}