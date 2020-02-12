#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int jobSize = jobs.size();
    int endTime = 0;
    vector<pair<int, int>> disks;
    for (int i = 0; i < jobs.size(); i++)
        disks.push_back(make_pair(jobs[i][0], jobs[i][1]));
    sort(disks.begin(), disks.end(), cmp);

    while (!disks.empty())
    {
        int size = disks.size();
        for (int i = 0; i < size; i++)
        {
            if (disks[i].first <= endTime)
            {
                endTime += disks[i].second;
                answer += endTime - disks[i].first;
                disks.erase(disks.begin() + i);
                break;
            }
            if (i == size - 1)
                endTime++;
        }
    }
    return answer / jobSize;
}

int main()
{
    cout << "answer: " << solution(vector<vector<int>>{{0, 3}, {1, 9}, {2, 6}}) << endl;
}