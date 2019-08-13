#include <iostream>
#include <vector>
using namespace std;

int main() {
	string two[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	string three = "dz=";
	string input, tmp;
	cin >> input;

	int p = 0;
	int output = 0;

	while (p < input.length()) {
		if (p == input.length() - 1) {
			output++;
			break;
		}
		tmp = "";
		tmp = string() + input[p] + input[p + 1];
		if (tmp == two[0] or tmp == two[1] or tmp == two[2] or tmp == two[3] or tmp == two[4] or tmp == two[5] or tmp == two[6]) {
			output++;
			p += 2;
			
		}
		else if (p == input.length() - 2) {
			output += 2;
			break;
		}
		else if (tmp + string() + input[p + 2] == three) {
			output++;
			p += 3;
		}
		else {
			output++;
			p += 1;
		}
	}

	printf("%d", output);
}