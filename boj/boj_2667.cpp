#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool matrix[26][26];
bool visited[26][26];
int n, cnt;

void dfs(int x, int y)
{
    if (visited[x][y])
        return;
    visited[x][y] = true;
    cnt++;
    if (x + 1 < n && matrix[x + 1][y])
        dfs(x + 1, y);
    if (x > 0 && matrix[x - 1][y])
        dfs(x - 1, y);
    if (y + 1 < n, matrix[x][y + 1])
        dfs(x, y + 1);
    if (y > 0 && matrix[x][y - 1])
        dfs(x, y - 1);
}

int main()
{
    string line;
    vector<int> result;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = line[j] == '1' ? true : false;
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] && !visited[i][j])
            {
                dfs(i, j);
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }

    printf("%d\n", result.size());
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        printf("%d\n", result[i]);
}