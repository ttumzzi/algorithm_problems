#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main(){
    int n;
    string command;
    cin >> n;

    while(n--){
        cin >> command;
        if(command == "push"){
            int x;
            cin >> x;
            v.push_back(x);
        }else if(command == "pop"){
            if(v.size() == 0)
                cout << -1 << '\n';
            else{
                cout << v.back() << '\n';
                v.pop_back();
            }
        }else if(command == "size"){
            cout << v.size() << '\n';
        }else if(command == "empty"){
            if(v.size() == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }else if(command == "top"){
            if(v.size() == 0)
                cout << -1 << '\n';
            else
                cout << v.back() << '\n';
        }
    }
}