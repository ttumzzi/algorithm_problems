#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct letter
{
    int num, idx;
};

bool cmp(letter a, letter b)
{
    if (a.num == b.num)
        return a.idx < b.idx;
    return a.num < b.num;
}

bool cmp2(letter a, letter b)
{
    return a.idx < b.idx;
}

string solution(string number, int k)
{
    string answer = "";
    vector<letter> v;
    for (int i = 0; i < number.length(); i++)
        v.push_back({number[i], i});
    sort(v.begin(), v.end(), cmp);
    vector<letter> removing_vector = vector<letter>(v.begin(), v.begin() + k);
    sort(removing_vector.begin(), removing_vector.end(), cmp2);

    for (int i = 0; i < number.length(); i++)
    {
        int front_idx = removing_vector.front().idx;
        if (i == front_idx)
            removing_vector.erase(removing_vector.begin());
        else
            answer.push_back(number[i]);
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    solution("4177252841", 4);
}