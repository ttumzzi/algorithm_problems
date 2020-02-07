#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
    int h, x, y;
} tomato;
int matrix[101][101][101];
int m, n, h;

int main()
{
    cin >> m >> n >> h;
    queue<tomato> q;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> matrix[i][j][k];
                if (matrix[i][j][k] == 1)
                    q.push({i, j, k});
            }

    while (!q.empty())
    {
        tomato tmp = q.front();
        int curDay = matrix[tmp.h][tmp.x][tmp.y];
        q.pop();
        // 위
        if (tmp.h > 0 && !matrix[tmp.h - 1][tmp.x][tmp.y])
        {
            q.push({tmp.h - 1, tmp.x, tmp.y});
            matrix[tmp.h - 1][tmp.x][tmp.y] = curDay + 1;
        }
        // 아래
        if (tmp.h + 1 < h && !matrix[tmp.h + 1][tmp.x][tmp.y])
        {
            q.push({tmp.h + 1, tmp.x, tmp.y});
            matrix[tmp.h + 1][tmp.x][tmp.y] = curDay + 1;
        }
        // 왼쪽
        if (tmp.y > 0 && !matrix[tmp.h][tmp.x][tmp.y - 1])
        {
            q.push({tmp.h, tmp.x, tmp.y - 1});
            matrix[tmp.h][tmp.x][tmp.y - 1] = curDay + 1;
        }
        // 오른쪽
        if (tmp.y + 1 < m && !matrix[tmp.h][tmp.x][tmp.y + 1])
        {
            q.push({tmp.h, tmp.x, tmp.y + 1});
            matrix[tmp.h][tmp.x][tmp.y + 1] = curDay + 1;
        }
        // 뒤
        if (tmp.x > 0 && !matrix[tmp.h][tmp.x - 1][tmp.y])
        {
            q.push({tmp.h, tmp.x - 1, tmp.y});
            matrix[tmp.h][tmp.x - 1][tmp.y] = curDay + 1;
        }
        // 앞
        if (tmp.x + 1 < n && !matrix[tmp.h][tmp.x + 1][tmp.y])
        {
            q.push({tmp.h, tmp.x + 1, tmp.y});
            matrix[tmp.h][tmp.x + 1][tmp.y] = curDay + 1;
        }
    }

    int max = -1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (!matrix[i][j][k])
                {
                    printf("-1\n");
                    return 0;
                }
                max = matrix[i][j][k] > max ? matrix[i][j][k] : max;
            }
        }
    }
    printf("%d\n", max - 1);
}