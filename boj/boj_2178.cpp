#include <iostream>
#include <queue>
using namespace std;

int matrix[101][101];
int res = 0, n, m;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        if (i == n - 1 && j == m - 1)
            return;
        q.pop();

        if (i < n - 1 && matrix[i + 1][j] == 1)
        {
            q.push(make_pair(i + 1, j));
            matrix[i + 1][j] = matrix[i][j] + 1;
        }
        if (j < m - 1 && matrix[i][j + 1] == 1)
        {
            q.push(make_pair(i, j + 1));
            matrix[i][j + 1] = matrix[i][j] + 1;
        }
        if (i > 0 && matrix[i - 1][j] == 1)
        {
            q.push(make_pair(i - 1, j));
            matrix[i - 1][j] = matrix[i][j] + 1;
        }
        if (j > 0 && matrix[i][j - 1] == 1)
        {
            q.push(make_pair(i, j - 1));
            matrix[i][j - 1] = matrix[i][j] + 1;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
            matrix[i][j] = tmp[j] - 48;
    }

    bfs(0, 0);
    printf("%d\n", matrix[n - 1][m - 1]);
}