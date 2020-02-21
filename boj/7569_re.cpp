#include <iostream>
#include <queue>
using namespace std;

int map[101][101][101];
int m, n, h;
int dz[6] = {1, -1, 0, 0, 0, 0}, dx[6] = {0, 0, 0, 1, 0, -1}, dy[6] = {0, 0, 1, 0, -1, 0};

struct tomato
{
    int z, x, y;
};

int main()
{
    queue<tomato> q;
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1)
                    q.push({i, j, k});
            }

    while (!q.empty())
    {
        int z = q.front().z, x = q.front().x, y = q.front().y;
        int level = map[z][x][y];
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
            if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nz][nx][ny] == 0)
            {
                q.push({nz, nx, ny});
                map[nz][nx][ny] = level + 1;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (map[i][j][k] == 0)
                {
                    cout << -1 << endl;
                    return 0;
                }
                if (map[i][j][k] > answer)
                    answer = map[i][j][k];
            }
        }
    }
    cout << answer - 1 << endl;
    return 0;
}