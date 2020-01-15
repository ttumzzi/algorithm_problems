#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll house[200000];

int main()
{
    ll n, c, i, dist, res = 0;
    scanf("%lld %lld", &n, &c);
    for (i = 0; i < n; i++)
        scanf("%lld", &house[i]);

    sort(house, house + n);
    ll start = 1, end = house[n - 1] - house[0];
    while (start <= end)
    {
        ll cnt = 1;
        ll prev = house[0];
        dist = (start + end) >> 1;
        for (i = 1; i < n; i++)
        {
            if (house[i] - prev >= dist)
            {
                cnt++;
                prev = house[i];
            }
        }
        if (cnt < c)
        {
            end = dist - 1;
        }
        else
        {
            start = dist + 1;
            res = res < dist ? dist : res;
        }
    }

    printf("%lld", res);
}