#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    int len = citations.size();
    sort(citations.begin(), citations.end());
    int start = 0, end = 1000, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int cnt = 0;
        for (int i = 0; i < len; i++)
        {
            if (citations[i] >= mid)
                cnt++;
        }
        if (cnt >= mid && len - cnt <= mid)
        {
            answer = mid;
            int plus = 1;
            while (true)
            {
                mid += plus;
                cnt = 0;
                for (int i = 0; i < len; i++)
                {
                    if (citations[i] >= mid)
                        cnt++;
                }
                if (cnt >= mid && len - cnt <= mid)
                    answer = mid;
                else
                    return answer;
            }
        }

        if (cnt >= mid && len - cnt > mid)
            end = mid - 1;
        else if (cnt < mid)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return answer;
}

int main()
{
    cout << solution(vector<int>{2, 7, 5}) << endl;
}