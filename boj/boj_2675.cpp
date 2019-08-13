#include <iostream>
using namespace std;

int main() {
	int test_case_num, iter_num;
	string s;
	cin >> test_case_num;

	for (int i = 0; i < test_case_num; i++) {
		cin >> iter_num;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			for (int k = 0; k < iter_num; k++)
				printf("%c", s[j]);
		printf("\n");
	}
}
