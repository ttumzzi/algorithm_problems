#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mat[20001][20001];
int visit[20001][20001];
int maximum = -1;

void dfs(int n, int number, int level)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mat[i][number] && !visit[i][number])
        {
            cnt++;
            dfs(n, i, level + 1);
        }
    }
    if (!cnt && level > maximum)
    {
        maximum = level;
        cnt = 0;
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    for (auto it = edge.begin(); it != edge.end(); it++)
        mat[(*it)[0]][(*it)[1]] = 1;
    dfs(n, 1, 0);
    answer = maximum;
    return answer;
}

int main()
{
    solution(6, vector<vector<int>>{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}