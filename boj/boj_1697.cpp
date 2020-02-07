#include <iostream>
#include <queue>
using namespace std;

int pos[100001];

int main()
{
    queue<int> q;
    int n, k;
    cin >> n >> k;
    q.push(n);
    pos[n] = 1;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        if (head - 1 >= 0 && !pos[head - 1])
        {
            q.push(head - 1);
            pos[head - 1] = pos[head] + 1;
        }
        if (head + 1 <= 100000 && !pos[head + 1])
        {
            q.push(head + 1);
            pos[head + 1] = pos[head] + 1;
        }
        if (head * 2 <= 100000 && !pos[head * 2])
        {
            q.push(head * 2);
            pos[head * 2] = pos[head] + 1;
        }

        if (pos[k])
        {
            printf("%d\n", pos[k] - 1);
            return 0;
        }
    }
}