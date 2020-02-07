#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cur_a = a;
    int cur_b = b;
    int round = 1;
    while (true)
    {
        printf("%d %d\n", cur_a, cur_b);
        //cur_a가 작고 홀수인 경우
        if (cur_b == cur_a + 1 && cur_a % 2)
            break;
        //cur_b가 작고 홀수인 경우
        if (cur_a == cur_b + 1 && cur_b % 2)
            break;
        round++;
        cur_a = (double)cur_a / 2 == (int)cur_a / 2 ? (cur_a / 2) : (cur_a / 2 + 1);
        cur_b = (double)cur_b / 2 == (int)cur_b / 2 ? (cur_b / 2) : (cur_b / 2 + 1);
    }

    return round;
}

int main()
{
    printf("%d\n", solution(16, 5, 12));
    // printf("%f\n", ceil((double)5 / 2));
}