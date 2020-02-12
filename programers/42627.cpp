#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int size = jobs.size();
    int time = 0;
    while (!jobs.empty())
    {
        sort(jobs.begin(), jobs.end(), cmp);
        for (int i = 0; i < jobs.size(); i++)
        {
            if (jobs[i][0] <= time)
            {
                answer += (time - jobs[i][0] + jobs[i][1]);
                time += jobs[i][1];
                jobs.erase(jobs.begin() + i);
                break;
            }
        }
    }
    return answer / size;
}

int main()
{
    vector<vector<int>> v{{0, 3}, {1, 9}, {2, 6}};
    cout << solution(v) << endl;
}