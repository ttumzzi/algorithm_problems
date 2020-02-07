#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
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
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(n);
        }
    }
}