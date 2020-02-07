#include <iostream>
#include <vector>
using namespace std;

int a[3] = {1, 2, 3};
int flag[3] = {0, 0, 0};

void dp(int n, int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < n; i++)
            if (flag[i])
                printf("%d ", a[i]);
        printf("\n");
        return;
    }

    flag[depth] = 1;
    dp(n, depth + 1);
    flag[depth] = 0;
    dp(n, depth + 1);
}

int main()
{
    dp(3, 0);
}