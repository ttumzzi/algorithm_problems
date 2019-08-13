#include <iostream>
using namespace std;

int main() {
	int d, t, start, end, output = 0;
	int l = 1;
	int r = 1;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> start >> end;
		d = end - start;
		while (d >= 0) {
			d -= l;
			d -= r;
			if (d > 0) {
				l++;
				r++;
				output += 2;
			}
			else if (d == 0) {
				break;
			}
			else {
				d += l;
				d += r;
				l++;
				output += 1;
			}
		}
	}
}