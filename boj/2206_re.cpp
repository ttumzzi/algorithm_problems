#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int dist[1001][1001][2];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct pos
{
    int x, y, w;
};

int main()
{
    queue<pos> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
            map[i][j] = line[j] == '1' ? 1 : 0;
    }
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, w = q.front().w;
        int level = dist[x][y][w];
        if (x == n - 1 && y == m - 1)
        {
            cout << level << endl;
            return 0;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny][w])
                continue;
            if (map[nx][ny] == 0)
            {
                dist[nx][ny][w] = level + 1;
                q.push({nx, ny, w});
            }
            if (map[nx][ny] == 1 && w == 0)
            {
                dist[nx][ny][1] = level + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    cout << -1 << endl;
}