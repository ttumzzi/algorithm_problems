#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x;
    string seq;
};
bool visit[10000];
char command[4] = {'D', 'S', 'L', 'R'};

int turn(int n, char direction) {
    int d[4];
    for (int i = 3; i >= 0; i--) {
        d[i] = n % 10;
        n /= 10;
    }
    int tmp;
    if (direction == 'L') {
        return d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[0];
    } else {
        return d[3] * 1000 + d[0] * 100 + d[1] * 10 + d[2];
    }
}

string bfs(int start, int end) {
    queue<node> q;
    q.push({start, ""});
    visit[start] = true;
    while (!q.empty()) {
        int x = q.front().x;
        string seq = q.front().seq;
        if (x == end) {
            return seq;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx;
            if (i == 0)
                nx = (x * 2) % 10000;
            else if (i == 1)
                nx = x == 0 ? 9999 : (x - 1);
            else if (i == 2)
                nx = turn(x, 'L');
            else if (i == 3)
                nx = turn(x, 'R');
            if (visit[nx]) continue;
            q.push({nx, seq + command[i]});
            visit[nx] = true;
        }
    }
}

int main() {
    int t;
    int start, end;
    cin >> t;
    while (t--) {
        cin >> start >> end;
        memset(visit, 0, sizeof(visit));
        cout << bfs(start, end) << endl;
    }
}