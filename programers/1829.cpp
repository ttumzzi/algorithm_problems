#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct elem
{
    int x, y;
};

int bfs(vector<vector<int> > &picture, int x, int y, int color, int m, int n)
{
    int cnt = 1;
    queue<elem> q;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    q.push({x, y});
    picture[x][y] = -1;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (picture[nx][ny] == color)
            {
                q.push({nx, ny});
                picture[nx][ny] = -1;
                cnt++;
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] > 0)
            {
                number_of_area++;
                int tmp = bfs(picture, i, j, picture[i][j], m, n);
                max_size_of_one_area = tmp > max_size_of_one_area ? tmp : max_size_of_one_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    vector<vector<int> > v{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    vector<int> ans = solution(6, 4, v);
    cout << ans[0] << " " << ans[1] << endl;
}