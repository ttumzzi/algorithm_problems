#include <stdio.h>
#include <algorithm>

int input[300];
int output[300];

int main(){
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        input[i] = n;
    }
    output[0] = input[0];
    output[1] = std::max(input[0] + input[1], input[1]);
    output[2] = std::max(input[1] + input[2], output[0] + input[2]);


    for(int i = 3; i < t; i++){
        output[i] = std::max(output[i-3] + input[i-1] + input[i], output[i-2] + input[i]);
    }

    printf("%d\n", output[t-1]);

    
}