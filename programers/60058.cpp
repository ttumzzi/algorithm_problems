#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isBalanced(string str)
{
    int left = 0, right = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
            left++;
        else
            right++;
    }
    return left == right;
}

bool isCorrect(string str)
{
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        if (stk.empty() || stk.top() == str[i])
            stk.push(str[i]);
        else
            stk.pop();

        if (stk.size() == 1 && stk.top() == ')')
            return false;
    }
    return stk.empty();
}

string swapString(string str)
{
    if (str == "")
        return str;
    string res = "";
    for (int i = 0; i < str.size(); i++)
        res += str[i] == ')' ? '(' : ')';
    return res;
}

string sequence(string p)
{
    if (p == "")
        return p;
    for (int i = 0; i < p.length(); i += 2)
    {
        string tmp = p.substr(0, i + 2);
        if (isBalanced(tmp))
        {
            string u = p.substr(0, i + 2);
            string v = (p.length() == u.length()) ? "" : p.substr(i + 2, p.length() - u.length());

            if (isCorrect(u))
                return (u + sequence(v));
            else
            {
                string emp = "(";
                emp += sequence(v) + ")";
                u = u.substr(1, u.size() - 1);
                u = u.substr(0, u.size() - 1);
                u = swapString(u);
                return emp + u;
            }
        }
    }
}

string solution(string p)
{
    string answer = "";
    if (isCorrect(p) || p.empty())
    {
        return p;
    }

    return sequence(p);
}

int main()
{
    cout << solution("(()())()") << endl;
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;
}