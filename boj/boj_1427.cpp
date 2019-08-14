#include <iostream>
#include <string>
using namespace std;

int cnt[10] = {0};

int main(){
    string num;
    cin >> num;
    int len = num.length();

    for(int i =0; i < len ; i++)
        cnt[(int)num[i] - 48]++;

    for(int i = 9; i >= 0; i--)
        for(int j = 0 ; j < cnt[i]; j++)
            printf("%d", i);
}