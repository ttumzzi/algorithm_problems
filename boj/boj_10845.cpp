#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    string cmd;
    vector <int> v;
    cin >> n;

    while(n--){
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            v.push_back(num);
        }else if(cmd == "pop"){
            if(v.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", v[0]);
            v.erase(v.begin());
        }else if(cmd == "size"){
            printf("%d\n", v.size());
        }else if(cmd == "empty"){
            printf("%d\n", v.empty());
        }else if(cmd == "front"){
            if(v.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", v[0]);
        }else if(cmd == "back"){
            if(v.size() == 0){
                printf("-1\n");
                continue;
            }
            printf("%d\n", v.back());
        }
    }
}