#include <iostream>
#include <queue>
using namespace std;

bool m[101][101];
bool visit[101];

int main()
{
    int answer = 0;
    int n, pairN;
    queue<int> q;
    cin >> n >> pairN;
    while (pairN--)
    {
        int x, y;
        cin >> x >> y;
        m[x][y] = true;
        m[y][x] = true;
    }
    q.push(1);
    visit[1] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        answer++;
        for (int i = 1; i <= n; i++)
        {
            if (m[front][i] && !visit[i])
            {
                q.push(i);
                visit[i] = true;
            }
        }
    }

    cout << answer - 1 << endl;
}