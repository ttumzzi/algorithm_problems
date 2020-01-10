#include <iostream >
#include <vector>
using namespace std;
typedef long long ll;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
        tree[node] = a[start];
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
    if (index < start || end < index)
        return;
    tree[node] += diff;
    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}