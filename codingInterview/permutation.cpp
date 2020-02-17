#include <iostream>
using namespace std;

void permutation(string str, string prefix)
{
    if (str.length() == 0)
        cout << prefix << endl;
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string tmp = str.substr(0, i) + str.substr(i + 1);
            permutation(tmp, prefix + str[i]);
        }
    }
}

int main()
{
    permutation("duck", "");
}
