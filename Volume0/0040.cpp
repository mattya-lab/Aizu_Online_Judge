#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int euclidean(double x) {
	int y = 0, flag = 0;

	for (int j = 0; j < 26; j++) {
		flag = (int)((double)x * (double)j) % 26;
		if (flag == 1) { y = j; }
	}
	return y;
}
int main(void) {
	int n = 1; (void)scanf("%d", &n);

	for (int z = 0; z < n; z++) {
		char s[256] = " ", t[256] = " ";
		fgets(s, 256, stdin); s[strlen(s) - 1] = '\0';
		int len_s = strlen(s) - 1;
		char cs[256] = " "; strcpy(cs, s);
		char* word[128];
		int len = 0;

		int a = 0, b = 0;
		word[0] = strtok(s, " ");
		for (unsigned int i = 1; word[i - 1] != NULL; i++) { word[i] = strtok(NULL, " "); len++; }
		for (int i = 0; i < len; i++) {
			if (strlen(word[i]) == 4)
			{
				int w0 = word[i][0] - 'a';
				int w1 = word[i][1] - 'a';

				int y0 = (26 + (w0 - w1)) % 26;
				int x0 = (26 + ('t' - 'a') - ('h' - 'a')) % 26;

				double a0 = (double)y0 / x0;
				int a_inverse = euclidean(a0);

				int b0 = (w0 - a_inverse * ('t' - 'a')) % 26;
				b0 = (b0 < 0) ? 26 + b0 : b0;

				char s1[4] = "";
				for (unsigned int j = 0; j < 4; j++) {
					int t1 = (word[i][j] - 'a' - b0) % 26;
					t1 = (t1 < 0) ? t1 + 26 : t1;
					s1[j] = (euclidean((double)a_inverse) * t1) % 26 + 'a';

					if (strncmp(s1, "that", 4) == 0 || strncmp(s1, "this", 4) == 0) {
						a = a_inverse;
						b = b0;
					}
				}
			}
		}

		for (int i = 0; i <= len_s; i++) {
			if (cs[i] == ' ') t[i] = ' ';
			else if (cs[i] == '.') t[i] = '.';
			else {
				int t1 = (cs[i] - 'a' - b) % 26;
				t1 = (t1 < 0) ? t1 + 26 : t1;
				t[i] = (euclidean((double)a) * t1) % 26 + 'a';
			}
		}
		printf("%s\n", t);
	}
	return 0;
}