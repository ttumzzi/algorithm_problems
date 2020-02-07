#include <iostream>
using namespace std;

#define ALPHABET 26

int main() {
	bool group_word = true;
	int input_num, output = 0;
	string input;
	char letter_before = '\0';
	int start_alphabet = (int)'a';
	int alphabet[ALPHABET];
	fill_n(alphabet, ALPHABET, 0);

	cin >> input_num;
	for (int i = 0; i < input_num; i++) {
		cin >> input;
		fill_n(alphabet, ALPHABET, 0);
		letter_before = '\0';
		group_word = true;
		for (int j = 0; j < input.length(); j++) {
			if (alphabet[input[j] - start_alphabet] == 0) {
				alphabet[input[j] - start_alphabet] = 1;
				letter_before = input[j];
			}
			else if ((int)alphabet[input[j] - start_alphabet] > 0 && letter_before != input[j]) {
				group_word = false;
				break;
			}
			else
				continue;
		}
		if (group_word)
			output++;
	}
	printf("%d", output);
}