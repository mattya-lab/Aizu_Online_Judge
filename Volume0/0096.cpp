#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int ans = 0;

void combination(int ele, int sum, int k, int n)
{
	sum = sum + ele;
	if (sum == n) {
		ans++; return; 
	}

	if (k > (3) || sum > n) { return; }

	for (int i = 0; i <= n; i++)
		combination(i, sum, k + 1, n);
}

int main(void)
{
	rep(z, 3) {
		ans = 0;
		int n; cin >> n;
		for (int i = 0; i <= n; i++) 
			combination(i, 0, 1, n);
		cout << ans  << endl;
	}
	return 0;
}