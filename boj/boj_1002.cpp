#include <stdio.h>
#include <math.h>

int main() {
	int t;
	double x1, y1, r1, x2, y2, r2, c, sum, sub;
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		c = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		sum = r1 + r2; sub = fabs(r2 - r1);
		if (c == 0 && sub == 0) printf("-1\n");
		else if (sub < c && sum > c) printf("2\n");
		else if (sum == c || sub == c) printf("1\n");
		else printf("0\n");
	}
}