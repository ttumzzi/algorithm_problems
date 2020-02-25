#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

//코드 정리해서 다시 풀기

int map1[301][301];
int map2[301][301];
int visit[301][301];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool melt(int year)
{
    int sea = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (year % 2 ? (!map2[i][j]) : (!map1[i][j]))
            {
                visit[i][j] = true;
                if (year % 2)
                    map1[i][j] = map2[i][j];
                else
                    map2[i][j] = map1[i][j];
                sea++;
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (year % 2 ? (!map2[nx][ny]) : (!map1[nx][ny]))
                    cnt++;
            }
            if (year % 2)
            {
                map1[i][j] = (map2[i][j] - cnt <= 0) ? 0 : (map2[i][j] - cnt);
                visit[i][j] = !map2[i][j] ? true : false;
            }
            else
            {
                map2[i][j] = (map1[i][j] - cnt <= 0) ? 0 : (map1[i][j] - cnt);
                visit[i][j] = !map1[i][j] ? true : false;
            }
        }
    }
    return sea == m * n;
}

void bfs(int x, int y, int year)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    while (!q.empty())
    {
        int fx = q.front().first, fy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = fx + dx[i], ny = fy + dy[i];
            if (visit[nx][ny])
                continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
}

int main()
{
    int year = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map1[i][j];

    while (true)
    {
        if (melt(year))
        {
            cout << 0 << endl;
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visit[i][j])
                {
                    if (cnt >= 1)
                    {
                        cout << year;
                        return 0;
                    }
                    bfs(i, j, year);
                    cnt++;
                }
            }
        }
        year++;
    }
}