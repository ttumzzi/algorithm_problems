#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
bool map[101][101];
int visit[101];

int bfs(int idx)
{
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(idx);
    visit[idx] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (map[front][i] && !visit[i])
            {
                q.push(i);
                visit[i] = visit[front] + 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (i != idx)
            sum += visit[i];
    return sum;
}

int main()
{
    int m;
    int answer_idx = 0, answer_num = 99999;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = true;
        map[y][x] = true;
    }

    for (int i = n; i >= 1; i--)
    {
        int res = bfs(i);
        if (res <= answer_num)
        {
            answer_num = res;
            answer_idx = i;
        }
    }
    cout << answer_idx;
}