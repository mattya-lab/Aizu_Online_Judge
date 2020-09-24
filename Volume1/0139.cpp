#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;

#define SIZE (255)

int SnakeType(char* s) {
	char t[2 + 1]; t[0] = s[0], t[1] = s[1]; t[2] = '\0';
	int len = 2;
	if (strcmp(t, ">'") == 0) {
		int cnt = 0;
		while (s[len] != '#') { 
			if (s[len] == '=') { len++; cnt++; }
			else { break; }
		}
		len++;
		while (cnt > 0) {
			if (s[len] == '=') { len++; cnt--; }
			else { break; }
		}
		if(s[len] == '~')
			return 0;
	}
	else if (strcmp(t, ">^") == 0) {
		while (s[len] != '~') {
			if (s[len] == 'Q' && s[len + 1] == '=') { len += 2; }
			else { break; }
		}
		if (s[len] == '~' && s[len + 1] == '~') {
			return 1;
		}
	}
	return -1;
}

int main(void) {
	int n; cin >> n;
	rep(i, n) {
		char s[SIZE] = " "; cin >> s;
		switch (SnakeType(s)) {
		case 0: cout << "A" << endl; break;
		case 1: cout << "B" << endl; break;
		default : cout << "NA" << endl; break;
		}
	}
	return 0;
}