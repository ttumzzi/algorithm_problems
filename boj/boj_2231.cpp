#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, num, distance;
	cin >> n;

	distance = (to_string(n).length() - 1) * 9;
	num = n - distance;

	for (int i = n < 10 ? 1 : n - distance; i < n; i++) {
		string num_str = to_string(i);
		int sum = i;
		for (int j = 0; j < num_str.length(); j++) {
			sum += num_str[j] - 48;
		}
		if (sum == n) {
			cout << num << endl;
			return 0;
		}
	}

	cout << "0" << endl;
	
}