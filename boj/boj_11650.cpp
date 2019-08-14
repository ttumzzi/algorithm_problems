#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, x, y;
    cin >> t;
    vector<pair<int,int> > v;

    for (int i = 0; i < t; i++){
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < t; i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
    
}