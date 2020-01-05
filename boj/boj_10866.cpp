#include <iostream>
#include <deque>
using namespace std;

int main(){
    int t, x;
    string cmd;
    deque <int> d;
    cin >> t;
    while(t--){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> x;
            d.push_front(x);
        }else if(cmd == "push_back"){
            cin >> x;
            d.push_back(x);
        }else if(cmd == "pop_front"){
            if(d.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", d.front());
            d.pop_front();
        }else if(cmd == "pop_back"){
            if(d.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", d.back());
            d.pop_back();
        }else if(cmd == "size"){
            printf("%d\n", d.size());
        }else if(cmd == "empty"){
            printf("%d\n", d.empty());
        }else if(cmd == "front"){
            if(d.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", d.front());
        }else if(cmd == "back"){
            if(d.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", d.back());
        }
    }
}