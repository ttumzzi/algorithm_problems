#include <iostream>
using namespace std;

int main() {
	int case_num, s_num, tot;
	float avg, result;
	int* score;

	cin >> case_num;
	for (int i = 0; i < case_num; i++) {
		cin >> s_num;
		tot = 0;
		result = 0;
		score = new int[s_num];
		for (int j = 0; j < s_num; j++) {
			cin >> score[j];
			tot += score[j];
		}
		avg = tot / s_num;
		for (int j = 0; j < s_num; j++)
			if (score[j] > avg)
				result++;
		result = (result / s_num) * 100;
		printf("%.3f%%\n", result);
	}
}