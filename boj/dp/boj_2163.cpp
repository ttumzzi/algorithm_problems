#include <stdio.h>

int d[301][301];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int d = m;
    int a = m - 1;
    int result = a + d * (n - 1);

    printf("%d\n", result);
}