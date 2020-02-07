#include <iostream>
using namespace std;

#define ALPHABET_NUM 26

int main() {
	int alphabet[ALPHABET_NUM];
	fill_n(alphabet, ALPHABET_NUM, 0);
	int upper_alphabet_start = (int)'A';
	int idx, max_idx = 0;
	bool duplicate_flag = false;
	string word;
	cin >> word;

	
	for (int i = 1; i < ALPHABET_NUM; i++) {
		if (alphabet[i] > alphabet[max_idx]) {
			max_idx = i;
			duplicate_flag = false;
		}
		else if (alphabet[i] == alphabet[max_idx])
			duplicate_flag = true;
	}

	if (duplicate_flag)
		printf("?");
	else
		printf("%c", (char)(max_idx + upper_alphabet_start));

}