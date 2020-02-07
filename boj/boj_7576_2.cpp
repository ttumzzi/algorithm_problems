#include <iostream>
#include <deque>
#include <vector>
using namespace std;

long long tomato[1001][1001];
bool visit[1001][1001];
deque<pair<long long, long long>> v;
deque<pair<long long, long long>>::iterator iter;
long long days = 0;
long long visitNum = 0;
long long m, n;

void bfs()
{
    deque<pair<long long, long long>> tmp;
    while (true)
    {
        long long size = v.size();
        for (long long i = 0; i < size; i++)
        {
            long long x = v[i].first;
            long long y = v[i].second;
            if (visit[x][y])
                continue;
            visit[x][y] = true;
            visitNum--;

            if (x + 1 < n && tomato[x + 1][y] == 0 && !visit[x + 1][y])
            {
                tmp.push_back(make_pair(x + 1, y));
            }
            if (y + 1 < m && tomato[x][y + 1] == 0 && !visit[x][y + 1])
            {
                tmp.push_back(make_pair(x, y + 1));
            }
            if (x > 0 && tomato[x - 1][y] == 0 && !visit[x - 1][y])
            {
                tmp.push_back(make_pair(x - 1, y));
            }
            if (y > 0 && tomato[x][y - 1] == 0 && !visit[x][y - 1])
            {
                tmp.push_back(make_pair(x, y - 1));
            }
        }
        while (size--)
            v.pop_front();
        size = tmp.size();
        for (long long i = 0; i < size; i++)
        {
            v.push_back(tmp[i]);
        }
        while (size--)
            tmp.pop_back();
        if (v.empty())
            return;
        else
            days++;
    }
}

int main()
{
    cin >> m >> n;
    visitNum = m * n;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                v.push_back(make_pair(i, j));
            if (tomato[i][j] == -1)
            {
                visit[i][j] = true;
                visitNum--;
            }
        }
    }
    bfs();
    if (visitNum != 0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", days);
}