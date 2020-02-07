#include <iostream>
#include<cmath>
using namespace std;

int main() {
	double v, a, b;

	scanf_s("%lf %lf %lf", &a, &b, &v);

	double with_b = v / (a - b);
	double without_b = (v - b) / (a - b);

	if (with_b > without_b)
		printf("%d", (int)ceil(without_b));
	else
		printf("%d", (int)ceil(with_b));


}