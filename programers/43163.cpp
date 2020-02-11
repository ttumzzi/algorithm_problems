#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct word
{
    string word;
    int cnt;
};

bool cmp(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
        if (cnt > 1)
            return false;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words)
{
    queue<string> q;
    map<string, int> m;
    int answer = 0;
    for (int i = 0; i < words.size(); i++)
        m.insert(make_pair(words[i], 0));

    m.find(begin)->second = 1;
    q.push({begin});
    while (!q.empty())
    {
        string curWord = q.front();
        int cnt = m.find(curWord)->second;
        cout << curWord << ' ' << cnt << endl;
        if (curWord.compare(target) == 0)
            return cnt - 1;
        q.pop();
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (cmp(it->first, curWord) && it->second == 0)
            {
                it->second = cnt + 1;
                q.push(it->first);
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"});
}