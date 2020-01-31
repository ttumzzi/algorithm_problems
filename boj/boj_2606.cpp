#include <iostream>
#include <queue>
using namespace std;

bool m[101][101];  //is connected?
bool visited[101]; //is visited?

int main()
{

    queue<int> q;
    int node, edge, x, y, result = 0;
    cin >> node >> edge;

    while (edge--)
    {
        cin >> x >> y;
        m[x][y] = true;
        m[y][x] = true;
    }

    visited[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int i = 1; i <= node; i++)
        {
            if (m[head][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                result++;
            }
        }
    }
    printf("%d\n", result);
}