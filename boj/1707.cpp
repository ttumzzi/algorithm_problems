#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int visit[20001];
map<int, vector<int>> m;

bool bfs(int n)
{
    queue<int> q;
    vector<int> v1, v2;
    q.push(n);
    visit[n] = 1;
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
        cin >> v >> e;
        m.clear();
        memset(visit, 0, sizeof(visit));
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            m[x].push_back(y);
            m[y].push_back(x);
        }
        bool flag = false;
        for (int i = 1; i <= v; i++)
        {
            if (!visit[i] && !m[i].empty())
            {
                if (!bfs(i))
                {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "NO" : "YES") << endl;
    }
}