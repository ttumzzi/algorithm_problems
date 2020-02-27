#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
    int x, weight;
};

map<int, vector<node>> m;
bool visit[10001];
node maxVal = {0, -1};

void dfs(int x, int w) {
    if (w >= maxVal.weight) maxVal = {x, w};
    for (auto elem : m[x]) {
        if (visit[elem.x]) continue;
        visit[elem.x] = true;
        dfs(elem.x, w + elem.weight);
    }
}

int main() {
    int n, parent, child, weight;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child >> weight;
        m[parent].push_back({child, weight});
        m[child].push_back({parent, weight});
    }

    visit[1] = true;
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    visit[maxVal.x] = true;
    dfs(maxVal.x, 0);
    cout << maxVal.weight << endl;
}