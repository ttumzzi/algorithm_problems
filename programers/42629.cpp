#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    int nextStart = stock;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    queue<pair<int, int>> tmp;
    for (int i = 0; i < dates.size(); i++)
        pq.push(make_pair(dates[i], supplies[i]));
    while (nextStart < k && !pq.empty())
    {
        if (pq.top().first > nextStart)
        {
            tmp.push(make_pair(pq.top().first, pq.top().second));
            pq.pop();
        }
        else if (pq.top().first <= nextStart)
        {
            nextStart += pq.top().second;
            pq.pop();
            answer++;

            for (int i = 0; i < tmp.size(); i++)
            {
                pq.push(make_pair(tmp.front().first, tmp.front().second));
                tmp.pop();
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution(4, vector<int>{4, 10, 15}, vector<int>{20, 5, 10}, 30) << endl;
}