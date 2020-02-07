#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct
{
    int score, name;
} student;

bool cmp(student a, student b)
{
    if (a.score == b.score)
    {
        return a.name < b.name;
    }
    else
    {
        return a.score > b.score;
    }
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int aAns = 0, bAns = 0, cAns = 0;
    string a = "12345";
    string b = "21232425";
    string c = "3311224455";
    int aLen = a.length();
    int bLen = b.length();
    int cLen = c.length();

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == (int)(a[i % aLen] - '0'))
            aAns++;
        if (answers[i] == (int)(b[i % bLen] - '0'))
            bAns++;
        if (answers[i] == (int)(c[i % cLen] - '0'))
            cAns++;
    }
    vector<student> tmp{{aAns, 1}, {bAns, 2}, {cAns, 3}};
    sort(tmp.begin(), tmp.end(), cmp);
    int max = tmp[0].score;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i].score == max)
            answer.push_back(tmp[i].name);
        else
            break;
    }

    return answer;
}

int main()
{
    vector<int> v{1, 3, 2, 4, 2};
    vector<int> ans = solution(v);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
}