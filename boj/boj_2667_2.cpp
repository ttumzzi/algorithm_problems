#include <iostream>
#include <vector>
using namespace std;

bool matrix[25][25];
bool visited[25][25];
int n;

int dfs(int x, int y)
{
    if (visited[x][y])
        return 0;
    visited[x][y] = true;
    int left = 0, right = 0, upper = 0, lower = 0;
    if (x + 1 < n && matrix[x + 1][y])
    {
        left = dfs(x + 1, y);
    }
    if (x > 0 && matrix[x - 1][y])
    {
        right = dfs(x - 1, y);
    }
    if (y + 1 < n, matrix[x][y + 1])
    {
        upper = dfs(x, y + 1);
    }
    if (y > 0 && matrix[x][y - 1])
    {
        lower = dfs(x, y - 1);
    }
    return left + right + upper + lower;
}

int main()
{
    int tmp;
    string line;
    vector<int> result;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = line[j] == '1' ? true : false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] && !visited[i][j])
            {
                tmp = dfs(i, j);
                result.push_back(tmp);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
}