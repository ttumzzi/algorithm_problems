#include <iostream>
#include <string>
using namespace std;

int main() {
	int result, n;
	string tmp;

	cin >> n;

	if (n < 100)
		result = n;
	else {
		result = 99;
		for (int i = 100; i <= n; i++) {
			tmp = to_string(i);
			if (tmp[0] - tmp[1] == tmp[1] - tmp[2])
				result++;
		}
	}
	
	printf("%d", result);
}