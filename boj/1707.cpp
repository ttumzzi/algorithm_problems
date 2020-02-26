#include <iostream>
#include <queue>
#include <map>
#include <string.h>
using namespace std;

map<int, vector<int>> m;
int visit[20001];

bool bfs(int i)
{
    queue<int> q;
    q.push(i);
    visit[i] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto k : m[x])
        {
            if (!visit[k])
            {
                q.push(k);
                visit[k] = -visit[x];
            }
            else if (visit[k] == visit[x])
                return false;
        }
    }
    return true;
}

int main()
{
    int t, v, e;
    cin >> t;
    while (t--)
    {
        m.clear();
        memset(visit, 0, sizeof(visit));
        cin >> v >> e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            m[a].push_back(b);
            m[b].push_back(a);
        }
        bool flag = true;
        for (int i = 1; i <= v; i++)
        {
            if (!m[i].empty() && !visit[i] && !bfs(i))
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}