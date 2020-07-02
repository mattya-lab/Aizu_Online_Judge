#include<iostream>
using namespace std;

int n;

int f(int a, int b, int i) {
	char s[100] = ""; for (int i = 0; i < n + 2; i++) { s[i] = '0'; }
	sprintf_s(s, "%lf", (double)a/b);
	return s[1 + i] - '0';
}

int main(void)
{
	for (int z = 0; z < 4; z++) {
		int a, b; cin >> a >> b >> n;
		int s = 0;
		for (int i = 1; i <= n; i++) { s = s + f(a, b, i); }
		cout << s << endl;
	}
	return 0;
}