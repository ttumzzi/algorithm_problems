#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

tuple<int, int, string> tpl[100000];


int main(){
    int t, age;
    string name;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        cin >> age >> name;
        tpl[i] = make_tuple(age, i, name);
    }

    sort(tpl, tpl + t);
    for(int i = 0 ; i < t; i ++){
        cout << get<0>(tpl[i]) << " " << get<2>(tpl[i]) << "\n";
    }
}