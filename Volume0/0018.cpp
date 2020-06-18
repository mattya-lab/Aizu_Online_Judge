#include<iostream>

int main(void)
{
	int a, b, c, d, e;
	(void)scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int s[5 + 1] = { a, b, c ,d, e };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			if (s[j] < s[j + 1]) {
				int tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", s[i]);
	}
	return 0;
}