#include <iostream>
using namespace std;

void swap(char &a, char &b) {
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	string a, b;
	int a_int, b_int;
	cin >> a;
	cin >> b;

	swap(a[0], a[2]);
	swap(b[0], b[2]);
	
	a_int = atoi(a.c_str());
	b_int = atoi(b.c_str());

	if (a_int > b_int)
		printf("%d", a_int);
	else
		printf("%d", b_int);
}

/*
	string a, b;
	int a_int, b_int;
	cin >> a;
	cin >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	a_int = atoi(a.c_str());
	b_int = atoi(b.c_str());

	if (a > b)
		printf("%d", a_int);
	else
		printf("%d", b_int);
*/