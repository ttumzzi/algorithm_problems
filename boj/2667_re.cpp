#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool mat[26][26];
bool visit[26][26];
int n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct node
{
    int x, y;
};

int bfs(int x, int y)
{
    queue<node> q;
    int cnt = 0;
    q.push({x, y});
    visit[x][y] = true;
    while (!q.empty())
    {
        int x_front = q.front().x, y_front = q.front().y;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x_front + dx[i], ny = y_front + dy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > n)
                continue;
            if (mat[nx][ny] && !visit[nx][ny])
            {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<int> answer;
    string line;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
            mat[i][j] = line[j] == '1' ? true : false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (mat[i][j] && !visit[i][j])
                answer.push_back(bfs(i, j));
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}