#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

int visit[10000];

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int getNumber(int num[4]) {
    return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
}

vector<int> getPossible(int x) {
    vector<int> result;
    int d[4], tmp[4];
    for (int i = 3; i >= 0; i--) {
        d[i] = x % 10;
        tmp[i] = d[i];
        x /= 10;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            tmp[i] = j;
            int newNum = getNumber(tmp);
            if (newNum >= 1000 && newNum != x && isPrime(newNum)) result.push_back(newNum);
        }
        tmp[i] = d[i];
    }
    return result;
}

int bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == target)
            return visit[x] - 1;

        vector<int> possibleNumber = getPossible(x);
        for (auto k : possibleNumber) {
            if (!visit[k]) {
                q.push(k);
                visit[k] = visit[x] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int t, start, end;
    cin >> t;
    while (t--) {
        cin >> start >> end;
        memset(visit, 0, sizeof(visit));
        int res = bfs(start, end);
        if (res == -1)
            cout << "Impossible" << endl;
        else
            cout << res << endl;
    }
}