#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int width, height;

struct node
{
    int x, y;
};

int bfs(int x, int y)
{
    int cnt = 0;
    queue<node> q;
    q.push({x, y});
    map[x][y] = 1;
    while (!q.empty())
    {
        int x_front = q.front().x, y_front = q.front().y;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x_front + dx[i], ny = y_front + dy[i];
            if (nx < 0 || nx >= height || ny < 0 || ny >= width)
                continue;
            if (!map[nx][ny])
            {
                q.push({nx, ny});
                map[nx][ny] = 1;
            }
        }
    }
    return cnt;
}

int main()
{
    int square_num;
    vector<int> answer;
    cin >> height >> width >> square_num;

    while (square_num--)
    {
        int xmin, ymin, xmax, ymax;
        cin >> xmin >> ymin >> xmax >> ymax;
        for (int i = ymin; i < ymax; i++)
        {
            for (int j = xmin; j < xmax; j++)
            {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (!map[i][j])
                answer.push_back(bfs(i, j));
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (auto it = answer.begin(); it != answer.end(); it++)
        cout << *it << ' ';
}