#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int totWeight = 0;
    queue<int> q;
    queue<int> waitingTrucks;
    for (int i = 0; i < truck_weights.size(); i++)
        waitingTrucks.push(truck_weights[i]);
    while (bridge_length--)
        q.push(0);

    q.pop();
    totWeight += waitingTrucks.front();
    q.push(waitingTrucks.front());
    waitingTrucks.pop();

    while (totWeight > 0)
    {
        answer++;
        if (q.front() != 0)
        {
            totWeight -= q.front();
            q.pop();
        }
        else
            q.pop();

        if (!waitingTrucks.empty())
        {
            int newTruckWeight = waitingTrucks.front();

            if (totWeight + newTruckWeight > weight)
                q.push(0);
            else
            {
                q.push(newTruckWeight);
                totWeight += newTruckWeight;
                waitingTrucks.pop();
            }
        }
    }
    return answer + 1;
}

int main()
{
    int n = solution(2, 10, vector<int>{7, 4, 5, 6});
    printf("%d\n", n);
}