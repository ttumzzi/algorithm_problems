#include <iostream>
#include <algorithm>
using namespace std;

long long a[500000];

int main()
{
    int n, m, i;
    long long tmp;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%lld", &tmp);
        printf("%d ", upper_bound(a, a + n, tmp) - lower_bound(a, a + n, tmp));
    }
}