#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        int progress = 100 - progresses[i];
        int leftDays = ceil(progress / speeds[i]);
        q.push(leftDays);
    }

    int max = q.front();
    int tmp = 1;
    q.pop();
    while (!q.empty())
    {
        if (q.front() <= max)
        {
            tmp++;
        }
        else
        {
            answer.push_back(tmp);
            max = q.front();
            tmp = 1;
        }
        q.pop();
    }
    answer.push_back(tmp);
    return answer;
}

int main()
{
    vector<int> p{93, 30, 55};
    vector<int> s{1, 30, 5};
    vector<int> res = solution(p, s);
    for (int i = 0; i < res.size(); i++)
    {
        printf("%d ", res[i]);
    }
}