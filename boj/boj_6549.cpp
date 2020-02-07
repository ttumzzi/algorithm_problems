#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

ll ans = 0;

void init(vector<ll> &a, vector<ll> &tree, ll node, ll start, ll end)
{
    if (start == end)
    {
        tree[node] = start;
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = a[tree[node * 2]] > a[tree[node * 2 + 1]] ? tree[node * 2 + 1] : tree[node * 2];
    }
}

ll query(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right)
{
    // if (node)
}

ll getMax(vector<ll> &a, vector<ll> &tree, ll start, ll end)
{
    ll minimum = a[tree[1]];
    ll len = end - start + 1;
    ll s = minimum * len;
    if (s > ans)
        ans = s;
    // getMax(a, tree, start, )
}

int main()
{
    while (true)
    {
        ll t, n;
        cin >> t;
        if (t == 0)
            return 0;
        vector<ll> arr(t);

        while (t--)
        {
            cin >> n;
            arr.push_back(n);
        }

        int h = (int)(ceil(log2(n)) + 1e-9);
        int tree_size = 1 << (h + 1);

        vector<ll> tree(tree_size);
        init(arr, tree, 1, 0, n - 1);

        for (int i = 0; i < tree.size(); i++)
            printf("%d ", tree[i]);

        // getMax(arr, tree, 0, t - 1);
    }
}