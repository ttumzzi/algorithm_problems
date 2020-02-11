#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    while (true)
    {
        if (pq.top() > K)
            return answer;
        if (pq.size() <= 1)
            return -1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
}

int main()
{
    vector<int> v{1, 2, 3, 9, 10, 12};
    cout << solution(v, 7) << endl;
}