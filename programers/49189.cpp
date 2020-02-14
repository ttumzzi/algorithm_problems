#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct node
{
    int idx, level;
};

int mat[20001][20001];
int visit[20001];

int solution(int n, vector<vector<int>> edge)
{
    int vec_size = edge.size() + 1;
    int answer = 0;
    int max = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        mat[edge[i][0]][edge[i][1]] = 1;
        mat[edge[i][1]][edge[i][0]] = 1;
    }
    queue<node> q;
    visit[1] = 1;
    q.push({1, 0});
    while (!q.empty())
    {
        int idx = q.front().idx;
        int level = q.front().level;
        if (level > max)
        {
            max = level;
            answer = 1;
        }
        else if (level == max)
        {
            answer++;
        }
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (mat[i][idx] && !visit[i])
            {
                visit[i] = 1;
                q.push({i, level + 1});
            }
        }
    }
    cout << answer;
    return answer;
}

int main()
{
    solution(20000, vector<vector<int>>{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}