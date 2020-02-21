#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct node
{
    int x, y;
};

int main()
{
    int n, m;
    queue<node> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
            map[i][j] = line[j] == '1' ? 1 : 0;
    }
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, len = map[x][y];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 1)
            {
                q.push({nx, ny});
                map[nx][ny] = len + 1;
            }
        }
    }
    cout << map[n - 1][m - 1];
}