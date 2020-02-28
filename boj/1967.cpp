#include <string.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
    int x, weight;
};
int nodeNum;
int visit[10001];
map<int, vector<node>> m;
node maxVal = {0, -1};

void dfs(int idx, int weight) {
    visit[idx] = true;
    if (weight > maxVal.weight) maxVal = {idx, weight};
    for (auto elem : m[idx]) {
        if (!visit[elem.x]) {
            dfs(elem.x, weight + elem.weight);
        }
    }
}

int main() {
    cin >> nodeNum;
    int parent, child, weight;
    for (int i = 0; i < nodeNum - 1; i++) {
        cin >> parent >> child >> weight;
        m[parent].push_back({child, weight});
        m[child].push_back({parent, weight});
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(maxVal.x, 0);
    cout << maxVal.weight << endl;
}