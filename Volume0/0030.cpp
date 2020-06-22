#include<iostream>
using namespace std;

int ans;

void combination(int sum,int k, int n, int s, int from, int to, bool flag) {
	if (k >= n || sum > s || from == to) { ; }
	else {
		if (flag == true) { sum = to; }
		if (sum == s && k == n - 1) { ans++; }
		for (int i = sum; i <= 9; i++) {
			combination(sum + i, k + 1, n, s, to, i, false);
		}
	}
}

int main(void)
{
	while (1) {
		int n, s; cin >> n >> s;
		ans = 0;
		if (n == 0 && s == 0) { break; }
		for (int i = 0; i < s; i++) { combination(0, 0, n, s, -1, i, true); }
		cout << ans << endl;
	}
	return 0;
}