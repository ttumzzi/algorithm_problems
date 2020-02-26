#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

bool visit[10001];
char word[4] = {'D', 'S', 'L', 'R'};

struct digit {
    int d1, d2, d3, d4;
};

struct pos {
    int number;
    string route;
};

int getNumber(digit num) {
    return num.d1 * 1000 + num.d2 * 100 + num.d3 * 10 + num.d4;
}

int leftTurn(int num) {
    int d[4];
    for (int i = 3; i >= 0; i--) {
        d[i] = num % 10;
        num /= 10;
    }
    return getNumber({d[1], d[2], d[3], d[0]});
}

int rightTurn(int num) {
    int d[4];
    for (int i = 3; i >= 0; i--) {
        d[i] = num % 10;
        num /= 10;
    }
    return getNumber({d[3], d[0], d[1], d[2]});
}

void bfs(int start, int end) {
    queue<pos> q;
    q.push({start, {}});
    visit[start] = true;

    while (!q.empty()) {
        int x = q.front().number;
        string route = q.front().route;
        if (x == end) {
            for (auto k : route) cout << k;
            cout << endl;
            return;
        }
        q.pop();
        int tmp[4];
        tmp[0] = (2 * x) % 10000;
        tmp[1] = x == 0 ? 9999 : (x - 1);
        tmp[2] = leftTurn(x);
        tmp[3] = rightTurn(x);
        for (int i = 0; i < 4; i++) {
            if (!visit[tmp[i]]) {
                route += word[i];
                q.push({tmp[i], route});
                visit[tmp[i]] = true;
                route.pop_back();
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> start >> end;

        memset(visit, 0, sizeof(visit));
        bfs(start, end);
    }
}