#include <iostream>
#include <queue>
using namespace std;

#define HORIZONTAL 1
#define VERTICAL 2
#define DIGAGONAL 3

int n;
int map[17][17];

struct node
{
    int head_x, head_y, tail_x, tail_y;
    int direction;
};

struct singleNode
{
    int x, y;
};

int main()
{
    queue<node> q;
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    q.push({0, 0, 0, 1, HORIZONTAL});
    while (!q.empty())
    {
        int head_x = q.front().head_x, head_y = q.front().head_y;
        int tail_x = q.front().tail_x, tail_y = q.front().tail_y;
        int direction = q.front().direction;
        q.pop();

        if (tail_x >= n || tail_y >= n)
            continue;

        if (tail_x == n - 1 && tail_y == n - 1)
        {
            answer++;
            continue;
        }

        singleNode left = {tail_x, tail_y + 1};
        singleNode diag = {tail_x + 1, tail_y + 1};
        singleNode down = {tail_x + 1, tail_y};

        if (direction == HORIZONTAL)
        {
            if (left.y < n && map[left.x][left.y] != 1)
                q.push({tail_x, tail_y, left.x, left.y, HORIZONTAL});
            if (left.y < n && down.x < n && diag.x < n && diag.y < n &&
                map[left.x][left.y] != 1 && map[down.x][down.y] != 1 && map[diag.x][diag.y] != 1)
                q.push({tail_x, tail_y, diag.x, diag.y, DIGAGONAL});
        }
        else if (direction == VERTICAL)
        {
            if (down.x < n && map[down.x][down.y] != 1)
                q.push({tail_x, tail_y, down.x, down.y, VERTICAL});
            if (left.y < n && down.x < n && diag.x < n && diag.y < n &&
                map[left.x][left.y] != 1 && map[down.x][down.y] != 1 && map[diag.x][diag.y] != 1)
                q.push({tail_x, tail_y, diag.x, diag.y, DIGAGONAL});
        }
        else
        {
            if (left.y < n && map[left.x][left.y] != 1)
                q.push({tail_x, tail_y, left.x, left.y, HORIZONTAL});
            if (down.x < n && map[down.x][down.y] != 1)
                q.push({tail_x, tail_y, down.x, down.y, VERTICAL});
            if (left.y < n && down.x < n && diag.x < n && diag.y < n &&
                map[left.x][left.y] != 1 && map[down.x][down.y] != 1 && map[diag.x][diag.y] != 1)
                q.push({tail_x, tail_y, diag.x, diag.y, DIGAGONAL});
        }
    }
    cout << answer << endl;
}