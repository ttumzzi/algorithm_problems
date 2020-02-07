#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    int t = commands.size();
    for (int i = 0; i < t; i++)
    {
        auto first = array.cbegin() + commands[i][0] - 1;
        auto last = array.cbegin() + commands[i][1];
        vector<int> tmp(first, last);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}

int main()
{
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int> > commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> res = solution(array, commands);

    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
}