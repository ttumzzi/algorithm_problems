#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int board[301][301];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
struct node
{
    int x, y;
};

int main()
{
    int t, l;
    node start, end;

    cin >> t;
    while (t--)
    {
        queue<node> q;
        cin >> l;
        memset(board, 0, sizeof(board));
        cin >> start.x >> start.y >> end.x >> end.y;
        q.push({start.x, start.y});
        board[start.x][start.y] = 1;
        while (!q.empty())
        {
            int x = q.front().x, y = q.front().y;
            q.pop();
            if (x == end.x && y == end.y)
            {
                cout << board[x][y] - 1 << endl;
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                if (!board[nx][ny])
                {
                    q.push({nx, ny});
                    board[nx][ny] = board[x][y] + 1;
                }
            }
        }
    }
}