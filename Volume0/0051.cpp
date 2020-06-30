#include<iostream>
#include<algorithm>
using namespace std;


int main(void) {
	int n; cin >> n;
	char s[256], t[256];
	int a[256];
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < strlen(s); j++) { a[j] = s[j] - '0'; }
		sort(a, a + strlen(s), greater<int>());
		for (int j = 0; j < strlen(s); j++) { s[j] = a[j] + '0'; }

		sort(a, a + strlen(s));
		for (int j = 0; j < strlen(s); j++) { t[j] = a[j] + '0'; }

		x = atoi(s);
		y = atoi(t);
		cout << x - y << endl;
	}
	return 0;
}