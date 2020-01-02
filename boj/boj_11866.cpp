#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, index = 0, i;
    cin >> n >> k;
    queue <int> q;
    for(i = 1; i <= n; i++){
        q.push(i);
    }

    printf("<");

    while(q.size() > 0){
        int tmp;
        for(i = 0; i < k-1; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        q.size()==1?printf("%d", q.front()):printf("%d, ", q.front());
        q.pop();
    }
    printf(">");
}