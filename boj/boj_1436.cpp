#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0, num = 665, found_num = 0;
	cin >> n;
	
	while(true) {
		string num_str = std::to_string(num);
		int found_idx = num_str.find("666");
		if (found_idx >= 0 && found_idx < num_str.length()) {
			found_num++;
		}

		if (found_num == n) {
			cout << num_str << endl;
			return 0;
		}
		
		num++;
	}
}