#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )
#define N (255)

void push(double* val, int* sp, double f) { val[(*sp)++] = f; }
double pop(double* val, int* sp) { return ((*sp) > 0) ? val[--(*sp)] : 0.0; }

int main(void) 
{
	rep(z, 3) {
		char s[N] = "";
		fgets(s, N, stdin); s[strlen(s) - 1] = '\0';
		char* ptr[N];
		int len = 0;
		ptr[0] = strtok(s, " "); 
		for (unsigned int i = 1; ptr[i - 1] != NULL; i++) { ptr[i] = strtok(NULL, " "); len++; }
		
		double val[N];
		int sp = 0;
		rep(i, len)
		{
			if (strcmp(ptr[i], "+") == 0 || strcmp(ptr[i], "-") == 0 ||
				strcmp(ptr[i], "*") == 0 || strcmp(ptr[i], "/") == 0)
			{
				char c = ptr[i][0];
				double f, op2;
				switch (c) {
				case '+':
					f = pop(val, &sp) + pop(val, &sp);
					push(val, &sp, f);
					break;

				case '-':
					op2 = pop(val, &sp);
					f = pop(val, &sp) - op2;
					push(val, &sp, f);
					break;

				case '*':
					f = pop(val, &sp) * pop(val, &sp);
					push(val, &sp, f);
					break;

				case '/':
					op2 = pop(val, &sp);
					f = pop(val, &sp) / op2;
					push(val, &sp, f);
					break;
				}
			}
			else{
				push(val, &sp, atof(ptr[i]));
			}
		}
		printf("%lf\n", val[0]);
	}
	return 0;
}