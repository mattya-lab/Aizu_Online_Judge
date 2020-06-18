#include<iostream>

int factorical(int n) { return (n == 1)? 1 : n * factorical(n - 1); }

int main(void)
{
	int n; (void)scanf("%d", &n);
	printf("%d", factorical(n));
	return 0;
}
