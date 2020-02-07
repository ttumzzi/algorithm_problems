#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct
{
    int x, y;
} pos;

// wall: 0 / not wall: not zero

int n, m;
int map[1001][1001];
int tmp[1001][1001];
vector<pos> collapsable;
vector<int> ans;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = map[i][j];
        }
}

int checkCollapsable()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            // if there is a wall.
            if (map[i][j] == 0)
            {
                if (j > 0 && j + 1 < m && map[i][j - 1] && map[i][j + 1])
                {
                    collapsable.push_back(pos{i, j});
                    if (i == 0 && j == 1)
                        return 1;
                }
                else if (i > 0 && i + 1 < n && map[i - 1][j] && map[i + 1][j])
                {
                    collapsable.push_back(pos{i, j});
                    if (i == 1 && j == 0)
                        return 1;
                }
            }
    return collapsable.size();
}

void bfs()
{
    queue<pos> q;
    q.push(pos{0, 0});
    while (!q.empty())
    {
        pos front = q.front();
        if (front.x == n - 1 && front.y == m - 1)
            break;
        q.pop();
        int curDist = tmp[front.x][front.y];
        if (front.x > 0 && tmp[front.x - 1][front.y] == 1)
        {
            q.push(pos{front.x - 1, front.y});
            tmp[front.x - 1][front.y] = curDist + 1;
        }
        if (front.x + 1 < n && tmp[front.x + 1][front.y] == 1)
        {
            q.push(pos{front.x + 1, front.y});
            tmp[front.x + 1][front.y] = curDist + 1;
        }
        if (front.y > 0 && tmp[front.x][front.y - 1] == 1)
        {
            q.push(pos{front.x, front.y - 1});
            tmp[front.x][front.y - 1] = curDist + 1;
        }
        if (front.y + 1 < m && tmp[front.x][front.y + 1] == 1)
        {
            q.push(pos{front.x, front.y + 1});
            tmp[front.x][front.y + 1] = curDist + 1;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = (line[j] - '0') == 0 ? 1 : 0;
            tmp[i][j] = map[i][j];
        }
    }

    int collapsableSize = checkCollapsable();
    if (collapsableSize == 0)
    {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < collapsableSize; i++)
    {
        init();
        int x = collapsable[i].x;
        int y = collapsable[i].y;
        tmp[x][y] = 1;
        bfs();
        if (tmp[n - 1][m - 1] != 1)
            ans.push_back(tmp[n - 1][m - 1]);
    }
    sort(ans.begin(), ans.end());
    if (ans[0] == 1)
        printf("-1\n");
    else
        printf("%d\n", ans[0]);
}