#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int t, n, order, target;
    queue <pair<int, int> > q;
    priority_queue <int> pq;
    cin >> t;
    while(t--){
        cin >> n >> order;
        int tmp, i;
        for(i = 0; i < n; i++){
            cin >> tmp;
            q.push(make_pair(tmp, i));
            pq.push(tmp);
        }

        i = 0;
        while(true){
            if(q.front().first < pq.top()){
                int tmp_order = q.front().first;
                int tmp_index = q.front().second;
                q.pop();
                q.push(make_pair(tmp_order, tmp_index));
            }

            if(q.front().first == pq.top()){
                if(q.front().second == order){
                    printf("%d\n", i + 1);
                    break;
                }   

                q.pop();
                pq.pop();
                i++;
            }

            
        }
        queue<pair<int,int> > emt1;
        swap(q, emt1);
        priority_queue<int> emt2;
        swap(pq, emt2);
    }
}