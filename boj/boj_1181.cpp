#include <iostream>
#include <algorithm>
using namespace std;

pair <int, string> p[20000];

bool compare(pair<int, string> p1, pair<int, string> p2){
    if(p1.first != p2.first){
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

int main(){
    int t;
    string word;
    string now_word = "-1";
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> word;
        
        p[i] = make_pair(word.length(), word);
    }
    
    sort(p, p+t);

    for(int i = 0 ; i < t; i++){
        if(now_word == p[i].second) continue;
        cout << p[i].second << "\n";
        now_word = p[i].second;
    }
}