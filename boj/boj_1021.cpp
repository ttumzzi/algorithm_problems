#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int n, m, target, tmp, result = 0;
    deque<int> d;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        d.push_back(i);
    }

    while(m--){
        cin >> target;
        if(d.front() == target){
            d.pop_front();
            continue;
        }
        deque<int>::iterator it = find(d.begin(), d.end(), target);
        int distance_front = distance(d.begin(), it);
        int distance_end = d.size() - distance_front;

        if(distance_front <= distance_end){
            result += distance_front;
            while(distance_front--){
                tmp = d.front();
                d.pop_front();
                d.push_back(tmp);
            }
        }else{
            result += distance_end;
            while(distance_end--){
                tmp = d.back();
                d.pop_back();
                d.push_front(tmp);
            }
        }
        d.pop_front();
    }
    printf("%d\n", result);
}