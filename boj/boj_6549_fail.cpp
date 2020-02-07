#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;
ll maxNum = 0;

ll getMax(ll col, ll n, ll psize){
    // printf("start: %d %d %d\n", n, col, psize);
    ll up = 0, left = 0;

    if((v.size() > col + 1) && (v[col + 1] >= n)) {
        // printf("go left\n");
        left = getMax(col + 1, n, psize + (n+1));
    }

    if(v[col] > n){
        // printf("go up => col: %d n: %d psize: %d\n", col, n, psize);
        if(col != 0 && (v[col-1] < n + 1)) {
            // printf("go up 1\n");
            up = getMax(col, n+1, n+2);
        }
        else if(col == 0) {
            // printf("go up 2 col:%d n:%d psize:%d \n", col, n, psize);
            up = getMax(col, n+1, n+2);
            }
    }

    if(psize>maxNum)maxNum = psize;
    if(up>maxNum)maxNum = up;
    if(left>maxNum)maxNum = left;
    // printf("psize: %d up: %d left: %d\n", psize, up, left);
    return maxNum;
}

int main(){
    while(true){
        ll t, n;
        cin >> t;
        if(t == 0) return 0;
        while(t--){
            cin >> n;
            v.push_back(n-1);
        }
        getMax(0, 0, 1);
        printf("%llu\n", maxNum);
        v.clear();
    }
}