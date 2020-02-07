#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[100000];

bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.first != p2.first){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(){
    int t, x, y;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
        p[i] = make_pair(y, x);
    }

    sort(p, p+t, compare);

    for(int i = 0 ; i < t; i++)
        printf("%d %d\n", p[i].second, p[i].first);

}