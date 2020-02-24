#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct pos
{
    int x, y;
};

int n;
char map[101][101];
bool visit[101][101];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool okay_to_go(char a, char b, bool weak)
{
    if (a == b)
        return true;
    if (weak)
    {
        if (a == 'G' && b == 'R')
            return true;
        if (a == 'R' && b == 'G')
            return true;
    }
    return false;
}

void bfs(int x, int y, bool weak)
{
    queue<pos> q;
    q.push({x, y});
    visit[x][y] = true;
    while (!q.empty())
    {
        int x_front = q.front().x, y_front = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x_front + dx[i], ny = y_front + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visit[nx][ny] || !okay_to_go(map[x_front][y_front], map[nx][ny], weak))
                continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
}

int main()
{
    string line;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
            map[i][j] = line[j];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visit[i][j])
            {
                bfs(i, j, false);
                cnt++;
            }
    cout << cnt << ' ';
    memset(visit, false, sizeof(visit));
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visit[i][j])
            {
                bfs(i, j, true);
                cnt++;
            }
    cout << cnt << endl;
}