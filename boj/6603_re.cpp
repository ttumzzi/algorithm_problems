#include <iostream>
#include <string.h>
using namespace std;

int map[14];
int visit[14];
int n;

void dfs(int level, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < n; i++)
            if (visit[i])
                cout << map[i] << ' ';
        cout << endl;
        return;
    }
    if (level == n)
        return;
    visit[level] = true;
    dfs(level + 1, cnt + 1);
    visit[level] = false;
    dfs(level + 1, cnt);
}

int main()
{
    while (true)
    {
        cin >> n;
        if (!n)
            return 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++)
            cin >> map[i];
        dfs(0, 0);
        cout << endl;
    }
}