#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> budgets, int M)
{
    int answer = 0;
    long long tmp = 0;
    long long upper = 1000000000;
    for (int i = 0; i < budgets.size(); i++)
        tmp += (budgets[i] > upper) ? upper : budgets[i];
    if (tmp > M)
    {
        int left = 0, right = upper;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            tmp = 0;
            for (int i = 0; i < budgets.size(); i++)
                tmp += (budgets[i] > mid) ? mid : budgets[i];
            if (tmp > M)
                right = mid - 1;
            else
                left = mid + 1;
        }
        answer = right;
    }
    else
        answer = *max_element(budgets.begin(), budgets.end());

    return answer;
}

int main()
{
    vector<int> v{120, 110, 140, 150};
    cout << solution(v, 485) << endl;
}