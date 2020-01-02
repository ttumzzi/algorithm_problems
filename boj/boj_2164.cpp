#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

int main(){
    int n, i, top;
    cin >> n;
    for(i = 1; i <= n; i++){
        q.push(i);
    }

    while(q.size() > 1){
        q.pop();
        top = q.front();
        q.pop();
        q.push(top);
    }

    printf("%d\n", q.front());
}