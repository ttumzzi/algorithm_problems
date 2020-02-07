#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	double n;
	scanf_s("%lf", &n);
	printf("%.6lf %.6lf", (M_PI * n * n), (2 * n * n));
}