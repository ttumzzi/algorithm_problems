#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int d[1001];
int card[1001];

int main(){
    int t;
    vector <int> v;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d", &card[i]);
    }

    d[1] = card[1];
    for(int i = 2; i <= t; i++){
        v.push_back(card[i]);
        for(int j = 1; j < i; j++)
            v.push_back(card[j] + d[i-j]);
        d[i] = *max_element(v.begin(), v.end());
        v.clear();
    }

    printf("%d\n", d[t]);
    
}
