#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++)
    {
        int tmp = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            tmp++;
            if (prices[j] < prices[i])
                break;
        }
        answer.push_back(tmp);
    }
    return answer;
}

int main()
{
    vector<int> v{1, 2, 3, 2, 3};
    vector<int> answer = solution(v);
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d ", answer[i]);
    }
}