#include <iostream>
#include <string>
using namespace std;

int main() {
	int output = 0;
	string sentence;
	
	getline(cin, sentence);

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ')
			output++;
	}

	if (sentence[0] == ' ')
		output--;
	if (sentence[sentence.length() - 1] == ' ')
		output--;

	printf("%d", output + 1);
}