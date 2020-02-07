#include <iostream>
using namespace std;

int main() {
	int alphabet[26];
	int tmp_num, output = 0;
	int start = (int)'A';
	string word;

	for (int i = 0; i < 15; i++) {
		tmp_num = i / 3 + 3;
		alphabet[i] = tmp_num;
	}

	for (int i = 15; i < 19; i++)
		alphabet[i] = 8;

	for (int i = 19; i < 22; i++)
		alphabet[i] = 9;

	for (int i = 22; i < 26; i++)
		alphabet[i] = 10;

	cin >> word;
	for (int i = 0; i < word.length(); i++)
		output += alphabet[(int)word[i] - start];
	
	printf("%d", output);
}