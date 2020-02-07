#include <stdio.h>
#define DEVIDING_NUM 10007

int main(){
    int n, a = 0, b = 1, c;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        c = (2 * a + b) % DEVIDING_NUM;
        a = b;
        b = c;
    }

    printf("%d\n", c);
}