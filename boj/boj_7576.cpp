#include <iostream>
#include <queue>
using namespace std;

struct t
{
    int x, y;
};

int tomato[1001][1001];
bool visit[1001][1001];
int days = 0;
int m, n;
queue<t> q;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        int curDay = tomato[x][y];
        if (x + 1 < n && tomato[x + 1][y] == 0)
        {
            q.push({x + 1, y});
            tomato[x + 1][y] = curDay + 1;
        }
        if (y + 1 < m && tomato[x][y + 1] == 0)
        {
            q.push({x, y + 1});
            tomato[x][y + 1] = curDay + 1;
        }
        if (x > 0 && tomato[x - 1][y] == 0)
        {
            q.push({x - 1, y});
            tomato[x - 1][y] = curDay + 1;
        }
        if (y > 0 && tomato[x][y - 1] == 0)
        {
            q.push({x, y - 1});
            tomato[x][y - 1] = curDay + 1;
        }
    }
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push({i, j});
            if (tomato[i][j] == -1)
            {
                visit[i][j] = true;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }
            if (tomato[i][j] > days)
                days = tomato[i][j];
        }
    }
    printf("%d\n", days - 1);
}