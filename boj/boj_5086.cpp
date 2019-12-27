#include <iostream>
using namespace std;

int main(){
    int x, y;
    int factor;
    int multiple;

    while(true){
        cin >> x >> y;
        if(x == 0 && y == 0)
            return 0;
        factor = y % x;
        multiple = x % y;

        if(factor == 0) printf("factor\n");
        else if(multiple == 0) printf("multiple\n");
        else printf("neither\n");
    }
}