#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
    }
    while (true)
    {
        int priority = q.front().first;
        int index = q.front().second;
        if (pq.top() == priority)
        {
            answer++;
            if (location == index)
                return answer;
            else
            {
                pq.pop();
                q.pop();
            }
        }
        else
        {
            q.pop();
            q.push(make_pair(priority, index));
        }
    }
}