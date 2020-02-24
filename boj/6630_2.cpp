#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int map[14], visit[14];

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++)
            cin >> map[i];
        for (int i = 6; i < n; i++)
            visit[i] = 1;
        do
        {
            for (int i = 0; i < n; i++)
            {
                if (!visit[i])
                    cout << map[i] << ' ';
            }
            cout << endl;

        } while (next_permutation(visit, visit + n));
        cout << endl;
    }
}