#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int mat[101][101];
bool visit[101];
int answer[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++)
    {
        memset(visit, false, sizeof(visit));
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int j = 0; j < n; j++)
            {
                if (mat[front][j] && !visit[j])
                {
                    q.push(j);
                    visit[j] = true;
                    answer[i][j] = 1;
                }
            }
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", answer[i][j]);
        printf("\n");
    }
}