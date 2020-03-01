#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y;
};
char map[12][6];
bool visit[12][6];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void removeEmpty() {
    for (int i = 0; i < 6; i++) {
        int idx = 11;
        for (int j = 11; j >= 0; j--) {
            if (map[j][i] == '.')
                continue;
            map[idx][i] = map[j][i];
            if (idx != j)
                map[j][i] = '.';
            idx--;
        }
    }
}

bool bfs(node no) {
    queue<node> q;
    vector<node> v;

    q.push(no);
    visit[no.x][no.y] = true;

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        v.push_back(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (map[nx][ny] == map[no.x][no.y] && !visit[nx][ny]) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
    if (v.size() >= 4) {
        for (auto elem : v)
            map[elem.x][elem.y] = '.';
        return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < 12; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 6; j++)
            map[i][j] = line[j];
    }

    int concat = 0;
    while (true) {
        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && !visit[i][j]) {
                    if (bfs({i, j})) cnt++;
                }
            }
        }
        if (cnt == 0) {
            printf("%d\n", concat);
            return 0;
        }
        removeEmpty();
        concat++;
    }
}