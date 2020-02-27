#include <string.h>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<int, vector<int>> m;
int visit[20001];

bool bfs(int idx) {
    queue<int> q;
    q.push(idx);
    visit[idx] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto k : m[x]) {
            if (!visit[k]) {
                q.push(k);
                visit[k] = -visit[x];
            } else if (visit[k] == visit[x]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t, v, e;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        memset(visit, 0, sizeof(visit));
        m.clear();
        while (e--) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            m[tmp1].push_back(tmp2);
            m[tmp2].push_back(tmp1);
        }
        bool flag = true;
        for (int i = 1; i <= v; i++) {
            if (!visit[i] && !bfs(i)) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}