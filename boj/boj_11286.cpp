#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top().second);
                pq.pop();
            }
        }
        else
        {
            pq.push(make_pair(n < 0 ? -1 * n : n, n));
        }
    }
}