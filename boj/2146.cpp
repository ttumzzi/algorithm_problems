#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 99999999

struct node {
    int x, y;
};

int n;
int map[101][101], visit[101][101];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<node> land;

void setColor(int landNum, int x, int y) {
    queue<node> q;
    q.push({x, y});
    map[x][y] = landNum;
    while (!q.empty()) {
        int fx = q.front().x, fy = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i], ny = fy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!map[nx][ny] || (map[nx][ny] == landNum)) continue;
            q.push({nx, ny});
            map[nx][ny] = landNum;
        }
    }
}

int bfs(node initNode) {
    queue<node> q;
    q.push(initNode);

    int startLand = map[initNode.x][initNode.y];
    visit[initNode.x][initNode.y] = 1;

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        if (map[x][y] != 0 && map[x][y] != startLand) {
            return visit[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (map[nx][ny] == startLand || visit[nx][ny]) continue;
            q.push({nx, ny});
            visit[nx][ny] = visit[x][y] + 1;
        }
    }
    return INF;
}

int main() {
    cin >> n;
    int answer = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j])
                land.push_back({i, j});
        }

    int landNum = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 1) {
                setColor(landNum, i, j);
                landNum++;
            }

    for (auto k : land) {
        memset(visit, 0, sizeof(visit));
        answer = min(answer, bfs(k));
    }
    cout << answer - 2 << endl;
}