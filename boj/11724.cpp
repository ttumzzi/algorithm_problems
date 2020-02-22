#include <iostream>
#include <queue>
using namespace std;

bool mat[1001][1001];
bool visit[1001];

int main()
{
    int n, m;
    int answer = 0;
    queue<int> q;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        mat[x][y] = true;
        mat[y][x] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            answer++;
            q.push(i);
            visit[i] = true;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (mat[front][j] && !visit[j])
                    {
                        visit[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    cout << answer << endl;
}