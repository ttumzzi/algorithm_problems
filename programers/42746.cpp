#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct nums
{
    int fixed, number;
};

bool desc(int a, int b)
{
    return a > b;
}

int getFixed(int num)
{
    string number = to_string(num);
    string res = "";
    for (int i = 0; i < 4; i++)
        res += number;
    res = res.substr(0, 4);
    return atoi(res.c_str());
}

bool cmp(nums a, nums b)
{
    return a.fixed > b.fixed;
}

string solution(vector<int> numbers)
{
    vector<nums> v;
    string answer = "";
    sort(numbers.begin(), numbers.end(), desc);
    for (int i = 0; i < numbers.size(); i++)
        v.push_back({getFixed(numbers[i]), numbers[i]});

    sort(v.begin(), v.end(), cmp);
    if (v[0].number == 0)
        return "0";
    for (int i = 0; i < v.size(); i++)
        answer += to_string(v[i].number);
    return answer;
}

int main()
{
    cout << solution(vector<int>{40, 403, 401}) << endl;
    cout << solution(vector<int>{40, 405}) << endl;
    cout << solution(vector<int>{40, 404}) << endl;
    cout << solution(vector<int>{12, 121}) << endl;
    cout << solution(vector<int>{2, 22, 223}) << endl;
    cout << solution(vector<int>{21, 212}) << endl;
    cout << solution(vector<int>{41, 415}) << endl;
    cout << solution(vector<int>{2, 22}) << endl;
    cout << solution(vector<int>{70, 0, 0, 0}) << endl;
    cout << solution(vector<int>{0, 0, 0, 0}) << endl;
    cout << solution(vector<int>{0, 0, 0, 1000}) << endl;
    cout << solution(vector<int>{12, 1213}) << endl;
}