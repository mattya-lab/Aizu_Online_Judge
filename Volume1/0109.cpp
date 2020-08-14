#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define SIZE (31)

int d[SIZE];
int dtop = 0;
int c[SIZE];
int ctop = 0;

void print();
int calc(int x, int y, char z);
void dpush(int val);
int dpop();
void cpush(char z);
char cpop();


int main(void)
{
	int n; cin >> n;
	rep(i, n)
	{
		char s[SIZE] = " "; cin >> s;
		rep(j, SIZE) d[j] = 0;
		rep(j, SIZE) c[j] = '\0';
		ctop = 0, dtop = 0;

		char cval[SIZE] = " ";
		int k = 0;
		int point = 0;

		for (unsigned int j = 0; j < strlen(s); j++) {
			if ('0' <= s[j] && s[j] <= '9') { cval[k] = s[j]; k++; }
			else {
				if(cval[0] != '\0') { dpush(atoi(cval)); }
				cpush(s[j]);

				rep(q, k) { cval[q] = '\0'; }
				k = 0;

				if (c[0] == '=') { continue; }

				if (s[j] == '=') {
					char u = cpop(); // '='
					while (true) {
						int op2 = dpop();
						int op1 = dpop();
						char x = cpop();
						dpush(calc(op1, op2, x));

						if (ctop == 0) { break; }
					}
				}
				if (s[j] == '(') { point = (ctop - 1); }

				if (s[j] == ')') {
					char u = cpop(); // ')'
					while (true) {
						// op1 + op2
						// op1 - op2
						// op1 * op2
						// op1 / op2
						int op2 = dpop();
						int op1 = dpop();
						char x = cpop();

						dpush(calc(op1, op2, x));

						if ((ctop - 1)== point) {
							cpop();
							break;
						}
					}
				}

				if (c[ctop - 1] == '+' || c[ctop - 1] == '-' || c[ctop - 1] == '*' || c[ctop - 1] == '/') {
					if ((c[ctop] != '(' || c[ctop] != ')') && d[dtop] != 0) {
						int op2 = dpop();
						int op1 = dpop();
						char x = cpop();
						dpush(calc(op1, op2, x));
					}
				}
				
				if ((c[ctop - 1] == '*' || c[ctop - 1] == '/') && (c[ctop] == '+' || c[ctop] == '-') && d[dtop] == 0) {
					int op2 = dpop();
					int op1 = dpop();
					char temp_c = cpop();
					char x = cpop();
					dpush(calc(op1, op2, x));
					cpush(temp_c);
				}
			}
		}
		cout << d[0] << endl;
		
	}
	return 0;
}

void cpush(char z) {
	c[ctop] = z;
	ctop++;
}

char cpop() {
	ctop--;
	char z = c[ctop];
	c[ctop] = '\0';
	return z;
}

void dpush(int val) {
	d[dtop] = val;
	dtop++;
}

int dpop() {
	dtop--;
	int val = d[dtop];
	d[dtop] = 0;
	return val;
}

int calc(int x, int y, char z) {
	switch (z) {
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}

void print() {
	cout << "-----------------------" << endl;
	for (int i = 4; i >= 0; i--)
		printf("d[%d]: %d c[%d]: %c\n", i, d[i], i, c[i]);
	printf("dtop: %d: ctop:%d\n", dtop, ctop);
}