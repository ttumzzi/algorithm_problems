#include <iostream>
using namespace std;

/*가능한 모든 조합*/

bool visit[5];
int arr[] = {1,2,3,4,5};

void dfs(int n){
    if(n == sizeof(arr)/sizeof(int)){
        for(int i =0;i<sizeof(visit)/sizeof(bool);i++){
            if(visit[i]){
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
    }else{
        visit[n] = true;
        dfs(n+1);
        visit[n] = false;
        dfs(n+1);
    }
}

int main(){
    dfs(0);
}

