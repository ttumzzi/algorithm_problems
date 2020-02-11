#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> s;
bool visit[8] = {
    0,
};

bool isPrime(int num)
{
    if (num == 1)
        return false;
    int i = 2;
    bool flag = false;
    while (i <= sqrt(num))
    {
        if (num % i == 0)
            return false;
        else
            i++;
    }
    return true;
}

void dfs(string numbers, int n)
{
    if (n == numbers.size())
    {
        string num = "";
        for (int i = 0; i < numbers.size(); i++)
            if (visit[i])
                num.push_back(numbers[i]);
        if (num[0] == '0' || num == "")
            return;
        s.insert(atoi(num.c_str()));
        return;
    }
    visit[n] = true;
    dfs(numbers, n + 1);
    visit[n] = false;
    dfs(numbers, n + 1);
}

int solution(string numbers)
{
    int answer = 0;
    vector<int> v;
    for (int i = 0; i < numbers.length(); i++)
        v.push_back(numbers[i]);
    sort(v.begin(), v.end());
    do
    {
        string num = "";
        for (auto it = v.begin(); it != v.end(); it++)
            num.push_back(*it);
        dfs(num, 0);
    } while (next_permutation(v.begin(), v.end()));

    for (auto iter = s.begin(); iter != s.end(); iter++)
    {
        if (isPrime(*iter))
            answer++;
    }
    return answer;
}

int main()
{
    // cout << solution("17") << endl;
    cout << solution("011") << endl;
}