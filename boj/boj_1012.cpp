#include <iostream>
using namespace std;

bool matrix[51][51];
bool visit[51][51];
int x, y;

void init()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            matrix[i][j] = false;
            visit[i][j] = false;
        }
    }
}

void dfs(int i, int j)
{
    if (visit[i][j])
        return;
    visit[i][j] = true;

    if (i + 1 < x && matrix[i + 1][j])
        dfs(i + 1, j);
    if (j + 1 < y && matrix[i][j + 1])
        dfs(i, j + 1);
    if (i > 0 && matrix[i - 1][j])
        dfs(i - 1, j);
    if (j > 0 && matrix[i][j - 1])
        dfs(i, j - 1);
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        cin >> y >> x >> n;
        init();
        while (n--)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            matrix[tmp2][tmp1] = true;
        }

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (matrix[i][j] && !visit[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}