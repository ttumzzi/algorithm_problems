#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll lan[10000];

int main()
{
    int k;
    ll n, start, end, mid, tmp = 0;
    bool found = false;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> lan[i];

    sort(lan, lan + k);

    start = 0;
    end = 10000000000001;
    while (start < end)
    {
        mid = (start + end) >> 1;
        tmp = 0;
        for (int i = 0; i < k; i++)
            tmp += (ll)(lan[i] / mid);
        if (tmp < n)
            end = mid;
        else
            start = mid + 1;
    }

    printf("%lld\n", start - 1);
}