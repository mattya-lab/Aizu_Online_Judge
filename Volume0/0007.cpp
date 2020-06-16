#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (k % i == 0) {
				cnt++;
			}
		}
		if (cnt == 2) ans++;
	}
	cout << ans << endl;
	return 0;
}