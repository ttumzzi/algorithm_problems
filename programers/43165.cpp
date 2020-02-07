#include <string>
#include <vector>

using namespace std;

int recursive(vector<int> &numbers, int target, int idx, char sign, int sum)
{
    sum += (numbers[idx]) * (sign == '+' ? 1 : -1);
    if (idx == numbers.size() - 1)
        return sum == target ? 1 : 0;

    return recursive(numbers, target, idx + 1, '+', sum) + recursive(numbers, target, idx + 1, '-', sum);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    answer += recursive(numbers, target, 0, '+', 0);
    answer += recursive(numbers, target, 0, '-', 0);
    return answer;
}

int main()
{
    printf("%d\n", solution(vector<int>{1, 1, 1, 1, 1}, 3));
}