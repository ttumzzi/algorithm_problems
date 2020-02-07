#include <string>
#include <vector>

using namespace std;

int student[31];

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    for (int i = 1; i <= n; i++)
        student[i] = 1;
    for (int i = 0; i < lost.size(); i++)
        student[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i]]++;

    for (int i = 1; i <= n; i++)
    {
        if (student[i] >= 1)
        {
            answer++;
            continue;
        }

        else if (student[i] == 0)
        {
            //앞사람 확인
            if (i > 1 && student[i - 1] == 2)
            {
                student[i - 1]--;
                student[i]++;
                answer++;
                continue;
            }
            // 뒷사람 확인
            if (i < n && student[i + 1] == 2)
            {
                student[i + 1]--;
                student[i]++;
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    printf("%d\n", solution(5, vector<int>{2, 4}, vector<int>{1, 3, 5}));
    printf("%d\n", solution(5, vector<int>{2, 4}, vector<int>{3}));
    printf("%d\n", solution(3, vector<int>{3}, vector<int>{1}));
}