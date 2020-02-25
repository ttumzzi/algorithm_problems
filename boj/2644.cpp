#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int visit[101];

int main()
{
    int n, me, target, t, answer = 0;
    queue<int> q;

    cin >> n >> me >> target >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    q.push(me);
    visit[me] = 1;
    while (!q.empty())
    {
        int front = q.front();
        if (front == target)
        {
            cout << visit[front] - 1 << endl;
            return 0;
        }
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (map[front][i] && !visit[i])
            {
                q.push(i);
                visit[i] = visit[front] + 1;
                answer++;
            }
        }
    }
    cout << -1 << endl;
}