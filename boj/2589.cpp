#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};
int map[50][50], visit[50][50];
int n, m, answer = -1;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int bfs(node init) {
    queue<node> q;
    memset(visit, 0, sizeof(visit));
    int maxDist = 0;
    q.push(init);
    visit[init.x][init.y] = 1;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, dist = visit[x][y];
        q.pop();
        if (dist > maxDist) maxDist = dist;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 0 || visit[nx][ny]) continue;
            q.push({nx, ny});
            visit[nx][ny] = dist + 1;
        }
    }
    return maxDist - 1;
}

int main() {
    cin >> n >> m;
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++)
            map[i][j] = line[j] == 'W' ? 0 : 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                answer = max(bfs({i, j}), answer);
            }
        }
    }

    cout << answer << endl;
}