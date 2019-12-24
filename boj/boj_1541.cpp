#include <iostream>
#include <string>
using namespace std;

int main(){
    string line, tmp;
    bool minus = false;
    cin >> line;
    int result = 0;

    for(int i = 0; i <= line.size(); i++){
        if(line[i] == '+' || line[i] == '-' || line[i] == '\0'){
            if (minus)
                result -= stoi(tmp);
            else
                result += stoi(tmp);
            tmp = "";
            if (line[i] == '-')
                minus = true;
            continue;
        }
        tmp += line[i];
    }
    printf("%d\n", result);
}