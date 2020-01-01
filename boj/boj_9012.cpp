#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, num = 0;
    string t;

    cin >> n;
    while(n--){
        cin >> t;
        while(true){
            if(t.find("()") == -1){
                printf("NO\n");
                break;
            }

            t.replace(t.find("()"), 2, "");
            if(t == ""){
                printf("YES\n");
                break;
            }
        }
    }
}