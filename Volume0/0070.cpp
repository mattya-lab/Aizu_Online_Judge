#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define vInt vector<int>

int ans = 0;

void Combination(int v, int t, int n, int s, const vInt memo) 
{
	if (t == n) { return; }

	for (int i = 0; i < memo.size(); i++) {
		if (v == memo[i]) return;
	}

	vInt copymemo;
	for (int i = 0; i < memo.size(); i++) copymemo.push_back(memo[i]);
	copymemo.push_back(v);

	int sum = 0;
	for (int i = 0; i < copymemo.size(); i++) { sum = sum + (i + 1) * copymemo[i]; }

	if (sum > s) { return ; }

	if (sum == s && t == n - 1) { ans++; }
	for (int i = 0; i <= 9; i++) Combination(i, t + 1, n, s, copymemo);

}

int main(void)
{
	rep(z, 2) {
		int n, s; cin >> n >> s;
		ans = 0;
		vInt memo;
		for (int i = 0; i <= 9; i++) { Combination(i, 0, n, s, memo); }
		cout << ans << endl;
	}
	return 0;
}