#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, h, w, n, xx, yy;
	cin >> t;
	while(t--){
		cin >> h >> w >> n;

		if (n % h == 0) {
			yy = h;
			xx = n / h;
		}
		else {
			yy = n % h;
			xx = (n / h) + 1;
		}

		printf("%d%02d\n", yy, xx);
	}
}