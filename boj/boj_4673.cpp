#include <iostream>
#include <string>
using namespace std;
#define MAX_NUM 10000

int sum_each_digits(int num) {
	string num_str = to_string(num);
	int rem = 0;
	int gen_num = num;
	for (int i = 0; i < num_str.length(); i++) {
		rem = num % 10;
		num /= 10;
		gen_num += rem;
	}
	return gen_num;
}

int main() {
	
	bool num_array[MAX_NUM + 1] = { false };
	int gen_num;

	for (int i = 1; i <= MAX_NUM; i++) {
		gen_num = sum_each_digits(i);
		if (gen_num <= MAX_NUM)
			num_array[gen_num] = true;
	}

	for (int j = 1; j <= MAX_NUM; j++)
		if (!num_array[j])
			printf("%d\n", j);
	
}