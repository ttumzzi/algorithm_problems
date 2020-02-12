#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int red)
{
    vector<int> answer;
    int width, height;
    int root = sqrt(red);
    for (int i = 1; i <= root; i++)
    {
        if (red % i == 0)
        {
            if (brown == 2 * (i + (red / i)) + 4)
            {
                width = i + 2;
                height = (red / i) + 2;
            }
        }
    }
    if (width > height)
    {
        answer.push_back(width);
        answer.push_back(height);
    }
    else
    {
        answer.push_back(height);
        answer.push_back(width);
    }
    return answer;
}

int main()
{
    vector<int> v = solution(24, 24);
    cout << v[0] << ' ' << v[1] << endl;
}