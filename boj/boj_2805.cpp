#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll tree[1000000];

int main()
{
    ll n, m, tmp, i, mid;
    scanf("%lld %lld", &n, &m);

    for (i = 0; i < n; i++)
        scanf("%lld", &tree[i]);

    ll start = 0, end = *max_element(tree, tree + n);
    while (start <= end)
    {
        ll mid = (start + end) >> 1;
        ll sum = 0;

        for (i = 0; i < n; i++)
            sum += (tree[i] - mid) > 0 ? tree[i] - mid : 0;

        if (sum < m)
            end = mid - 1;
        else
            start = mid + 1;
    }
    printf("%lld\n", end);
}