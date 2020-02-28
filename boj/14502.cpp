#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y;
};
int map[8][8], visit[8][8];
int wall[64];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, possibleSafeNum, answer = -1;
vector<node> virusInit;

node getNode(int num) {
    return {num / m, num % m};
}

void bfs() {
    int safeArea = possibleSafeNum;
    queue<node> q;
    for (auto elem : virusInit) {
        q.push(elem);
        visit[elem.x][elem.y] = true;
    }
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        safeArea--;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] || visit[nx][ny]) continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
    if (safeArea > answer) answer = safeArea;
}

void makeWalls(int idx, int level) {
    node no = getNode(idx);
    if (level == 3) {
        for (int i = 0; i < n * m; i++) {
            if (wall[i]) {
                node wallNode = getNode(i);
                map[wallNode.x][wallNode.y] = 1;
            }
        }
        memset(visit, 0, sizeof(visit));
        bfs();
        for (int i = 0; i < n * m; i++) {
            if (wall[i]) {
                node wallNode = getNode(i);
                map[wallNode.x][wallNode.y] = 0;
            }
        }
        return;
    }
    if (idx >= n * m) return;
    if (!map[no.x][no.y]) {
        wall[idx] = true;
        makeWalls(idx + 1, level + 1);
    }
    wall[idx] = false;
    makeWalls(idx + 1, level);
}

int main() {
    cin >> n >> m;
    possibleSafeNum = n * m - 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) virusInit.push_back({i, j});
            if (map[i][j] == 1) possibleSafeNum--;
        }
    }

    makeWalls(0, 0);
    cout << answer << endl;
}