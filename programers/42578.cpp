#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool visit[31] = {
    0,
};

int dfs(vector<int> v, int level)
{
    if (level == v.size())
    {
        int mult = 1;
        for (int i = 0; i < v.size(); i++)
            if (visit[i])
                mult *= v[i];
        return mult;
    }
    visit[level] = true;
    int t = dfs(v, level + 1);
    visit[level] = false;
    int f = dfs(v, level + 1);
    return t + f;
}

int solution(vector<vector<string>> clothes)
{
    vector<string> type;
    vector<int> v;
    int answer = 0;
    for (int i = 0; i < clothes.size(); i++)
    {
        int flag = -1;
        for (int j = 0; j < type.size(); j++)
        {
            if (type[j].compare(clothes[i][1]) == 0)
            {
                flag = j;
                break;
            }
        }
        if (flag == -1)
        {
            type.push_back(clothes[i][1]);
            v.push_back(1);
        }
        else
            v[flag]++;
    }

    answer = dfs(v, 0);

    return answer - 1;
}

int main()
{
    cout << solution(vector<vector<string>>{{"crow", "face"}, {"blue", "face"}, {"smoky", "face"}});
}