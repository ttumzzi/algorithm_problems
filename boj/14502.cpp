#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

struct node
{
    int x, y;
};

int map[9][9];
int visit[9][9];
int n, m, mapSize, answer = -1;
vector<node> v;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

node getNode(int i)
{
    return {i / m, i % m};
}

int bfs(node w1, node w2, node w3)
{
    queue<node> q;
    memset(visit, 0, sizeof(visit));
    int vir_num = 0;
    for (auto k : v)
    {
        q.push(k);
        visit[k.x][k.y] = 1;
    }
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        vir_num++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 1 || visit[nx][ny])
                continue;
            if (nx == w1.x && ny == w1.y)
                continue;
            if (nx == w2.x && ny == w2.y)
                continue;
            if (nx == w3.x && ny == w3.y)
                continue;
            q.push({nx, ny});
            visit[nx][ny] = 1;
        }
    }
    return mapSize - vir_num;
}

int main()
{
    cin >> n >> m;
    mapSize = n * m - 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                v.push_back({i, j});
            if (map[i][j] == 1)
                mapSize--;
        }

    for (int i = 0; i < n * m - 2; i++)
    {
        for (int j = i + 1; j < n * m - 1; j++)
        {
            for (int k = j + 1; k < n * m; k++)
            {
                node w1 = getNode(i);
                node w2 = getNode(j);
                node w3 = getNode(k);

                answer = max(answer, bfs(w1, w2, w3));
            }
        }
    }
    cout << answer << endl;
}