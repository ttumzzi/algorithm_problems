#include <stdio.h>

int main() {
	int x, y, w, h, min;
	scanf_s("%d %d %d %d", &x, &y, &w, &h);
	
	min = x;
	if (min > y)
		min = y;
	if (min > w-x)
		min = w-x;
	if (min > h-y)
		min = h-y;

	printf("%d", min);
}