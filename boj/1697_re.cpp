#include <iostream>
#include <queue>
using namespace std;

int visit[100001];

struct pos
{
    int idx, sec;
};

int main()
{
    int n, k;
    int answer = 0;
    queue<pos> q;
    cin >> n >> k;
    q.push({n, 0});
    while (!q.empty())
    {
        int x = q.front().idx, sec = q.front().sec;
        q.pop();
        if (x == k)
        {
            cout << sec << endl;
            return 0;
        }
        if (x + 1 <= 100000 && !visit[x + 1])
        {
            q.push({x + 1, sec + 1});
            visit[x + 1] = true;
        }
        if (x - 1 >= 0 && !visit[x - 1])
        {
            q.push({x - 1, sec + 1});
            visit[x - 1] = true;
        }
        if (x * 2 <= 100000 && !visit[x * 2])
        {
            q.push({x * 2, sec + 1});
            visit[x * 2] = true;
        }
    }
}