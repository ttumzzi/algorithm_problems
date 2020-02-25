#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

struct node
{
    int idx;
    bool flag;
};

int visit[20001];
map<int, vector<int>> m;

bool check(int x, vector<int> v)
{
    for (auto k : v)
        for (auto l : m[k])
            if (l == x)
                return false;
    return true;
}

bool bfs(int n)
{
    queue<node> q;
    vector<int> v1, v2;
    q.push({n, 0});
    visit[n] = 1;
    while (!q.empty())
    {
        int x = q.front().idx, flag = q.front().flag;
        if (flag)
        {
            if (check(x, v1))
                v1.push_back(x);
            else
                return false;
        }
        else
        {
            if (check(x, v2))
                v2.push_back(x);
            else
                return false;
        }
        q.pop();
        for (auto k : m[x])
        {
            if (!visit[k])
            {
                q.push({k, !flag});
                visit[k] = 1;
            }
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
            if (!visit[i])
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