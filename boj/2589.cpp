#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct pos
{
    int x, y;
};

int map[51][51];
int visit[51][51];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m;

int bfs(pos start)
{
    queue<pos> q;
    int maximum = -1;
    memset(visit, 0, sizeof(visit));
    q.push({start.x, start.y});
    visit[start.x][start.y] = 1;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        maximum = max(maximum, visit[x][y]);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!map[nx][ny] || visit[nx][ny])
                continue;
            q.push({nx, ny});
            visit[nx][ny] = visit[x][y] + 1;
        }
    }
    return maximum - 1;
}

int main()
{
    vector<pos> v;
    int answer = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
            map[i][j] = line[j] == 'L' ? 1 : 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j])
                answer = max(answer, bfs({i, j}));
        }
    }
    cout << answer << endl;
}