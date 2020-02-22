#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, len;
    cin >> n;
    for (int t = 0; t < n; t++)
    {
        int answer = 0;
        cin >> len;
        string correct, uncorrect;
        cin >> correct >> uncorrect;
        for (int i = 0; i < len; i++)
            if (correct[i] == uncorrect[i])
                answer++;
        printf("#%d %d\n", t + 1, answer);
    }
}
