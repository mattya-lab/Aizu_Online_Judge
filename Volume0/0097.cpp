#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int ans;

void combination(int sum, int k, int n, int s, int from, int to) {
	if (k >= n || sum > s || from == to) { ; }
	else {
		if (sum == s && k == n - 1) { ans++; }
		for (int i = sum; i <= s; i++) {
			combination(sum + i, k + 1, n, s, to, i);
		}
	}
}

int main(void)
{
	while (1) {
		int n, s; cin >> n >> s;
		ans = 0;
		if (n == 0 && s == 0) { break; }
		for (int i = 0; i < s; i++) { combination(i, 0, n, s, -1, i); }
		cout << ans << endl;
	}
	return 0;
}
