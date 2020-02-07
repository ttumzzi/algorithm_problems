#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	string input;
	int output = 0;
	cin >> num;
	cin >> input;

	
	for (int i = 0; i < num; i++) {
		output += (int)input[i] - 48;
	}
	

	printf("%d", output);
}