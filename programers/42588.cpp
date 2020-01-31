#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> result;
    bool flag = false;
    for (int i = heights.size() - 1; i >= 0; i--)
    {
        flag = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (heights[j] > heights[i])
            {
                result.push_back(j + 1);
                flag = true;
                break;
            }
        }
        if (!flag)
            result.push_back(0);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(9);
    v.push_back(9);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(2);
    vector<int> res = solution(v);
    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
}