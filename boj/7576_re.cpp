#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct tomato
{
    int x, y;
};

int main()
{
    int n, m;
    queue<tomato> q;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, len = map[x][y];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 0)
            {
                q.push({nx, ny});
                map[nx][ny] = len + 1;
            }
        }
    }

    int answer = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
            else if (map[i][j] > answer)
                answer = map[i][j];
        }
    }
    cout << answer - 1;
}