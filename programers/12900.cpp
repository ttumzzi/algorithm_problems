#include <iostream>
using namespace std;
#define mod 1000000007

int dp[60001];

int solution(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    if (n <= 2)
        return dp[n];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    return dp[n] % mod;
}

int main()
{
    dp[1] = 1;
}