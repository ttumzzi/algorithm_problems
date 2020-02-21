#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool mat[51][51];
bool visit[51][51];
int m, n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void dfs(int x, int y)
{
    if (visit[x][y])
        return;
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (mat[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    int t, x, y, k;
    cin >> t;
    while (t--)
    {
        int answer = 0;
        memset(mat, 0, sizeof(mat));
        memset(visit, 0, sizeof(visit));
        cin >> m >> n >> k;

        while (k--)
        {
            cin >> x >> y;
            mat[y][x] = true;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] && !visit[i][j])
                {
                    dfs(i, j);
                    answer++;
                }
            }
        }
        printf("%d\n", answer);
    }
}