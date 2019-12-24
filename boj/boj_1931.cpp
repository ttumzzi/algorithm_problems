#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}


int main(){
    int n, a, b;
    int cnt, last;
    vector<pair<int, int> > v;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    last = v.at(0).second;
    cnt = 1;
    for(int i = 1; i < n; i++){
        if(v.at(i).first >= last){
            last = v.at(i).second;
            cnt++;
        }
    }

    printf("%d\n", cnt);
    

}