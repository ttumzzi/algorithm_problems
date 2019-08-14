#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_NUM 500000

vector<int> v;

/* first int: repeated, second int: value */
vector<pair<int, int> > mode;
int repeat_num = 0;
int num_before = -4001;

bool compare(pair<int, int> p1, pair<int, int> p2){
	if(p1.first == p2.first)
		return p1.second < p2.second;
	else
		return p1.first > p2.first;
}

int main() {
	int t, n, sum = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		v.push_back(n);
		sum += n;
	}

	/*avg*/
	double avg = double(sum) / double(t);
	printf("%0.0lf\n", avg);

	sort(v.begin(), v.end());
	
	/*mid*/
	int mid = (t - 1) / 2;
	printf("%d\n", v.at(mid));

	/*mode*/
	if(t == 1)
		printf("%d\n", v.at(0));
	else{
		for(int i = 0; i < t; i++){
		if(num_before == v.at(i))
			repeat_num++;
		else
		{
			mode.push_back(make_pair(repeat_num, num_before));
			repeat_num = 1;
		}
		num_before = v.at(i);
	}

	mode.push_back(make_pair(repeat_num, num_before));

	sort(mode.begin(), mode.end(), compare);

	if(mode.at(0).first == mode.at(1).first)
		printf("%d\n", mode.at(1).second);
	else
		printf("%d\n", mode.at(0).second);
	}

	/*max-min*/
	printf("%d", v.at(t-1)-v.at(0));



}