#include <iostream>
#include <cmath>
using namespace std;

long long solution(int w, int h)
{
    long long wid = (long long)w;
    long long hei = (long long)h;
    long long answer = 0, upper, lower;
    long long i;
    for (i = 0; i < wid / 2; i++)
    {
        upper = ceil((long double)(i + 1) * hei / wid);
        lower = floor((long double)i * hei / wid);
        answer += (upper - lower) << 1;
    }
    if (wid % 2)
    {
        upper = ceil((long double)(i + 1) * hei / wid);
        lower = floor((long double)i * hei / wid);
        answer += (upper - lower);
    }

    return wid * hei - answer;
}

int main()
{
    cout << solution(8, 12) << endl;
}