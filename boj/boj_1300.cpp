#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k, i;
    scanf("%lld\n%lld", &n, &k);

    ll left = 1, right = k, ans;
    while (left <= right)
    {
        ll mid = (left + right) >> 1;
        ll cnt = 0;
        for (i = 1; i <= min(mid, n); i++)
            cnt += min(mid / i, n);

        if (cnt < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("%lld\n", left);
}