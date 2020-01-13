#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

void exist(int size, int n)
{
    int start = 0, end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (a[mid] == n)
        {
            printf("1\n");
            return;
        }
        else if (a[mid] > n)
            end = mid - 1;
        else
            start = mid + 1;
    }
    printf("0\n");
}

int main()
{
    int n, m, i, tmp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &tmp);
        exist(n, tmp);
    }
}