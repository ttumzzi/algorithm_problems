#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s, tmp;
    while(true){
        getline(cin, s);
        if(s == ".") return 0;

        tmp = s;
        tmp.erase(remove_if(tmp.begin(), tmp.end(), [](char c) { return isalpha(c); } ), tmp.end());
        tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
        tmp.erase(remove(tmp.begin(), tmp.end(), '.'), tmp.end());

        if(tmp == ""){
            printf("yes\n");
            continue;
        }

        while(true){
            if(tmp.find("()") == -1 && tmp.find("[]") == -1){
                printf("no\n");
                break;
            }
            if(tmp.find("()") != -1)
                tmp.replace(tmp.find("()"), 2, "");
            
            if(tmp.find("[]") != -1)
                tmp.replace(tmp.find("[]"), 2, "");

            if(tmp == ""){
                printf("yes\n");
                break;
            }
        }
    }
}