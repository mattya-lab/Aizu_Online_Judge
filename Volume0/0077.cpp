#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void) {
	rep(z, 2) {
		char s[50] = ""; cin >> s;
		char t[100] = "";
		int k = 0;

		for (unsigned int i = 0; i < strlen(s); i++) {
			if (s[i] == '@') {
				int len = s[i + 1] - '0';
				rep(j, len) {
					t[k] = s[i + 2]; k++;
				}
				i = i + 2;
			}
			else {
				t[k] = s[i]; k++;
			}
		}
		cout << t << endl;
	}
	return 0;
}