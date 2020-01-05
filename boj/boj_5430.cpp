#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <deque>
#include <sstream>
using namespace std;

int main(){
    int t, n, stop = 0, i;
    bool head = true;
    string cmd, tmp;
    deque<int> d;
    cin >> t;
    while(t--){
        stop = 0;
        head = true;
        d.clear();
        
        cin >> cmd;
        cin >> n;
        cin >> tmp;
        tmp.erase(0,1);
        tmp.erase(tmp.length()-1, 1);
        stringstream ss(tmp);

        string str;
        for(i = 0; i < n; i++){
            getline(ss, tmp, ',');
            d.push_back(atoi(tmp.c_str()));
        }

        for(i = 0; i < cmd.length(); i++){
            if(cmd[i] == 'R'){
                head==true?head=false:head=true;
            }else if(cmd[i] == 'D'){
                if(d.size() == 0){
                    printf("error\n");
                    stop = 1;
                    break;
                }
                head==true?d.pop_front():d.pop_back();
            }
        }

        if(stop == 0){
            printf("[");
            int size = d.size();
            for(int i = 0; i < size;i++){
                if(head){
                    i==size-1?printf("%d",d.front()):printf("%d,",d.front());
                    d.pop_front();
                }else{
                    i==size-1?printf("%d",d.back()):printf("%d,",d.back());
                    d.pop_back();
                }
            }
                
            printf("]\n");
        }
    }
}