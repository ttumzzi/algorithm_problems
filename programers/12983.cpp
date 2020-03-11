#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int result[20001];

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int maximum = t.size();
    int i, j, p, q;

    for (i = 0; i < maximum; i++)
    {
        result[i] = maximum + 1;
        for (j = 0; j < strs.size(); j++)
        {
            p = strs[j].size() - 1;
            for (q = 0; q < strs[j].size(); q++)
            {
                if ()
            }
        }
    }
}

int main()
{
    vector<string> strs = {"app", "ap", "p", "l", "e", "ple", "pp"};
    printf("%d\n", solution(strs, "apple"));
}