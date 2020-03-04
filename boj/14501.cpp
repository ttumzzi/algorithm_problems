#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct work {
    int start, end, pay;
};
int d[16];
vector<work> v;
int n;

bool cmp(work a, work b) {
    return a.end < b.end;
}

int main() {
    int duration, pay;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> duration >> pay;
        v.push_back({i, i + duration - 1, pay});
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        while (!v.empty() && v.front().end == i) {
            cnt++;
            d[i] = max({d[v.front().start - 1] + v.front().pay, d[i], d[i - 1]});
            v.erase(v.begin());
        }
        if (!cnt) d[i] = d[i - 1];
    }
    cout << d[n] << endl;
}