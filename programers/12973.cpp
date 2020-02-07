#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }
    if (st.empty())
        return 1;
    else
        return 0;
}

int main()
{
    string s = "baabaa";
    printf("%d\n", solution(s));
    s = "cdcd";
    printf("%d\n", solution(s));
}