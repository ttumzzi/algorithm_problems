#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, int> m;
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++)
    {
        m[clothes[i][1]]++;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1);
    }

    return answer - 1;
}

int main()
{
    cout << solution(vector<vector<string>>{{"crow", "face"}, {"blue", "face"}, {"smoky", "face"}});
}