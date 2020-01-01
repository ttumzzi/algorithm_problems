#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int case_num, n;
    string category, name;
    vector <string> v;
    vector<string>::iterator iter;
    int arr[100]; // 카테고리 별 아이템 개수
    int item_num = 0;

    cin >> case_num;
    while(case_num--){
        cin >> n;
        while(n--){
            cin >> name >> category;
            iter = find(v.begin(), v.end(), category);
            if(iter == v.end()){
                arr[item_num++] = 1;
                v.push_back(category);
            }
            else{
                int index = distance(v.begin(), iter);
                arr[index]++;
            }
        }
        int result = 1;
        for(int i = 0; i < item_num; i++)
            result *= (arr[i]+1);
        printf("%d\n", result - 1);

        v.clear();
        item_num = 0;
    }

}