#include <iostream>
#include <queue>
using namespace std;

int org[101][101];
int map[101][101];
int n, maximum = -1;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, int pivot)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    map[x][y] = -1;
    while (!q.empty())
    {
        int x_front = q.front().first, y_front = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x_front + dx[i], ny = y_front + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (map[nx][ny] > pivot)
            {
                q.push({nx, ny});
                map[nx][ny] = -1;
            }
        }
    }
}

int main()
{
    int answer = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> org[i][j];
            maximum = org[i][j] > maximum ? org[i][j] : maximum;
        }

    for (int pivot = 0; pivot <= maximum; pivot++)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                map[i][j] = org[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] > pivot)
                {
                    bfs(i, j, pivot);
                    tmp++;
                }
            }
        answer = tmp > answer ? tmp : answer;
    }
    cout << answer << endl;
}