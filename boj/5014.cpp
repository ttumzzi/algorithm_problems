#include <iostream>
#include <queue>
using namespace std;

int building[1000001];
int moving[2];

int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    moving[0] = u, moving[1] = -1 * d;
    queue<int> q;

    q.push(s);
    building[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        if (x == g)
        {
            cout << building[x] - 1;
            return 0;
        }
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int nx = x + moving[i];
            if (nx < 1 || nx > f || building[nx])
                continue;
            q.push(nx);
            building[nx] = building[x] + 1;
        }
    }
    cout << "use the stairs" << endl;
}