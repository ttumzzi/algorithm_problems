#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
    int x, y;
};

int n, m, wallNum = 3;
int map[8][8], visit[8][8];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int answer = -1;
vector<node> virus;

node getNode(int num)
{
    return {num / m, num % m};
}

void bfs()
{
    int virNum = 0;
    memset(visit, 0, sizeof(visit));
    queue<node> q;
    for (auto k : virus)
    {
        q.push(k);
        visit[k.x][k.y] = 1;
    }
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        virNum++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] || visit[nx][ny])
                continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
    int safeNum = m * n - virNum - wallNum;
    answer = safeNum > answer ? safeNum : answer;
}

void makeWall(int num, vector<int> v)
{

    node curNode = getNode(num);
    if (v.size() >= 3)
    {
        for (auto k : v)
            map[getNode(k).x][getNode(k).y] = 1;
        bfs();
        for (auto k : v)
            map[getNode(k).x][getNode(k).y] = 0;
        return;
    }
    if (num == n * m)
        return;
    makeWall(num + 1, v);
    if (!map[curNode.x][curNode.y])
    {
        v.push_back(num);
        makeWall(num + 1, v);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back({i, j});
            if (map[i][j] == 1)
                wallNum++;
        }

    makeWall(0, {});
    cout << answer << endl;
}