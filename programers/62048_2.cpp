#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long solution(int w, int h)
{
    long long s = (long long)w * (long long)h;
    long long b = (long long)w + (long long)h - gcd(w, h);
    return s - b;
}