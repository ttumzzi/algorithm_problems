#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001][3];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

    int r = a[0][0], g = a[0][1], b = a[0][2];
    for (int i = 1; i < n; i++) {
        int new_r, new_g, new_b;
        new_r = a[i][0] + min(g, b);
        new_g = a[i][1] + min(r, b);
        new_b = a[i][2] + min(r, g);
        r = new_r, g = new_g, b = new_b;
    }
    printf("%d\n", min({r, g, b}));
}