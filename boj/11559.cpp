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

void gravity() {
    for (int i = 0; i < 6; i++) {
        int idx = 12;
        for (int j = 11; j >= 0; j--) {
            if (map[j][i] == '.')
                continue;
            idx--;
            if (j == idx) continue;
            map[idx][i] = map[j][i];
            map[j][i] = '.';
        }
    }
}

bool bfs(node no) {
    queue<node> q;
    vector<node> v;
    q.push({no.x, no.y});
    visit[no.x][no.y] = true;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        v.push_back({x, y});
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
    int answer = 0;

    for (int i = 0; i < 12; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 6; j++)
            map[i][j] = line[j];
    }

    while (true) {
        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && !visit[i][j])
                    if (bfs({i, j})) cnt++;
            }
        }
        if (cnt == 0) {
            cout << answer << endl;
            return 0;
        }

        answer++;
        gravity();
    }
}