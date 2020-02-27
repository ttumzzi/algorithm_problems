#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int x, y, h;
};
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int map[300][300], visit[300][300];

bool melting() {
    vector<node> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (!map[nx][ny]) cnt++;
                }
                v.push_back({i, j, cnt});
            }
        }
    }

    if (v.empty()) return true;

    for (auto k : v) {
        map[k.x][k.y] -= k.h;
        map[k.x][k.y] = max(0, map[k.x][k.y]);
    }

    return false;
}

void dfs(node no) {
    if (visit[no.x][no.y]) return;
    visit[no.x][no.y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = no.x + dx[i], ny = no.y + dy[i];
        if (map[nx][ny]) dfs({nx, ny});
    }
}

int main() {
    int year = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    while (true) {
        year++;
        if (melting()) {
            cout << 0 << endl;
            return 0;
        }
        memset(visit, 0, sizeof(visit));

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] && !visit[i][j]) {
                    cnt++;
                    if (cnt >= 2) {
                        cout << year << endl;
                        return 0;
                    }
                    dfs({i, j});
                }
            }
        }
    }
}