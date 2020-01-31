#include <string>
#include <iostream>
#include <vector>
using namespace std;

int getDigit(int n)
{
    int digit = 0;
    int three = 3;
    while (n > 0)
    {
        n -= three;
        three *= 3;
        digit++;
    }
    return digit;
}

string solution(int n)
{
    string answer = "";
    int digit = getDigit(n);
    if (digit == 1)
    {
        answer = to_string(n == 3 ? 4 : n);
        return answer;
    }
    n--;
    int zero = 3;
    int scope = 3;
    int tmp = n % 3;
    tmp++;
    tmp = (tmp == 3) ? 4 : tmp;
    answer = to_string(tmp);
    for (int i = 1; i < digit; i++)
    {
        tmp = n;
        tmp -= zero;
        tmp /= scope;
        tmp %= 3;
        tmp++;
        answer = to_string(tmp == 3 ? 4 : tmp) + answer;
        scope *= 3;
        zero += scope;
    }
    return answer;
}

int main()
{
    cout << solution(10000000) << endl;
    cout << solution(2) << endl;
}