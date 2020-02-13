#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        internal.push_back(temp);
    }

    return internal;
}

vector<int> solution(vector<string> operations)
{
    /*
    set<int> s;
    *s.begin() // minValue in the set
    *s.rbegin() // maxValue in the set
    */
    set<int> pq;
    while (!operations.empty())
    {
        vector<string> splited = split(operations.front(), ' ');
        string cmd = splited[0];
        int num = atoi(splited[1].c_str());

        if (cmd.compare("I") == 0)
            pq.insert(num);
        else
        {
            if (!pq.empty())
            {
                auto it = pq.find(num == -1 ? *pq.begin() : *pq.rbegin());
                pq.erase(it);
            }
        }
        operations.erase(operations.begin());
    }
    if (pq.empty())
        return vector<int>{0, 0};
    else
        return vector<int>{*pq.rbegin(), *pq.begin()};
}

int main()
{
    vector<int> v = solution(vector<string>{"I 7", "I 5", "I -5", "D -1"});
    cout << v[0] << ' ' << v[1] << endl;
}