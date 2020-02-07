#include <iostream>
using namespace std;

#define ALPHABET_NUM 26

int main() {
	int alphabet[ALPHABET_NUM];
	fill_n(alphabet, ALPHABET_NUM, -1);
	int idx;
	string word;
	int starting_alphabet = (int)'a';

	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		idx = (int)word[i] - starting_alphabet;
		if (alphabet[idx] == -1)
			alphabet[idx] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << ' ';
}