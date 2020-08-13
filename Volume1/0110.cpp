#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

#define SIZE (31)

void splitToElements(char* s, char* ca, char* cb, char* cc);
void checkEquation(int i, int* val, char* ca, char* cb, char* cc);

int main(void)
{
	rep(z, 3)
	{
		char s[SIZE] = " "; cin >> s;
		char ca[SIZE] = " ", cb[SIZE] = " ", cc[SIZE] = " ";
		splitToElements(s, ca, cb, cc);
		
		int val = 0;
		if (ca[0] == 'X' || cb[0] == 'X' || cc[0] == 'X') {
			for(int i = 1; i < 10; i++)
				checkEquation(i, &val, ca, cb, cc);
		}
		else {
			rep(i, 10) checkEquation(i, &val, ca, cb, cc);
		}

		if (val == 0) { cout << "NA" << endl; }
		else { cout << val << endl; }
		
	}
	return 0;
}

void checkEquation(int i, int* val, char* ca, char* cb, char* cc) {
	char a[SIZE] = " ", b[SIZE] = " ", c[SIZE] = " ";
	strcpy(a, ca);
	strcpy(b, cb);
	strcpy(c, cc);

	rep(j, strlen(a)) {
		if (a[j] == 'X') { a[j] = i + 48; }
	}
	rep(j, strlen(b)) {
		if (b[j] == 'X') { b[j] = i + 48; }
	}
	rep(j, strlen(c)) {
		if (c[j] == 'X') { c[j] = i + 48; }
	}

	if (atoi(a) + atoi(b) == atoi(c)) {
		*(val) = i;
	}
}

void splitToElements(char* s, char* ca, char* cb, char* cc) {
	int cnt = 0;
	int k = 0;
	for (unsigned int i = 0; i < strlen(s); i++) {
		if (s[i] == '+' || s[i] == '=') {
			cnt++;
			k = 0;
			continue;
		}
		switch (cnt) {
		case 0: ca[k] = s[i]; k++; break;
		case 1: cb[k] = s[i]; k++; break;
		case 2: cc[k] = s[i]; k++; break;
		default: break;
		}
	}
}