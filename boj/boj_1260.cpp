#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool line[1001][1001];
bool visited[1001];

void dfs(int v)
{
    if (visited[v])
        return;
    visited[v] = true;
    cout << v << ' ';
    for (int i = 1; i <= n; i++)
    {
        if (line[v][i])
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        int front = q.front();
        for (int i = 1; i <= n; i++)
        {
            if (line[front][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
        printf("%d ", front);
        q.pop();
    }
}

int main()
{
    int v, i;
    int tmp1, tmp2;
    queue<int> q;
    cin >> n >> m >> v;

    for (i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        line[tmp1][tmp2] = true;
        line[tmp2][tmp1] = true;
    }

    dfs(v);
    for (i = 0; i <= n; i++)
        visited[i] = false;
    printf("\n");
    bfs(v);
}