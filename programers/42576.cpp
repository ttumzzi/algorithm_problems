#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    while (!completion.empty())
    {
        string parFront = participant.back();
        string comFront = completion.back();
        if (parFront == comFront)
        {
            participant.pop_back();
            completion.pop_back();
        }
        else
        {
            answer = parFront;
            return answer;
        }
    }
    return participant.back();
}
