#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y;
};

int map[8][8];
bool walls[64], visit[8][8];
int n, m, possibleSafeArea, answer = -1;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<node> initVirus;

void bfs() {
    int safeArea = possibleSafeArea;
    queue<node> q;
    memset(visit, 0, sizeof(visit));
    for (auto k : initVirus) {
        q.push(k);
        visit[k.x][k.y] = true;
    }
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        safeArea--;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 1 || visit[nx][ny]) continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
    if (safeArea > answer) answer = safeArea;
}

node getNode(int num) {
    return {num / m, num % m};
}

void makeWalls(int idx, int level) {
    node no = getNode(idx);
    if (level == 3) {
        for (int i = 0; i < n * m; i++)
            if (walls[i]) {
                node newWall = getNode(i);
                map[newWall.x][newWall.y] = 1;
            }
        bfs();
        for (int i = 0; i < n * m; i++)
            if (walls[i]) {
                node newWall = getNode(i);
                map[newWall.x][newWall.y] = 0;
            }
        return;
    }
    if (idx >= n * m) return;
    if (!map[no.x][no.y]) {
        walls[idx] = true;
        makeWalls(idx + 1, level + 1);
    }
    walls[idx] = false;
    makeWalls(idx + 1, level);
}

int main() {
    scanf("%d %d", &n, &m);
    possibleSafeArea = n * m - 3;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                possibleSafeArea--;
            else if (map[i][j] == 2)
                initVirus.push_back({i, j});
        }
    makeWalls(0, 0);
    cout << answer << endl;
}