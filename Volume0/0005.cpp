#include<iostream>
#include<stdio.h>
int gcd(int x, int y) { return (x % y == 0) ? y : gcd(y, x % y); }

int main(void) {
	for (int i = 0; i < 2; i++) {
		int a, b;
		(void)scanf("%d %d", &a, &b);
		printf("%d %d\n", gcd(a, b), a / gcd(a, b) * b);
	}
	return 0;
}