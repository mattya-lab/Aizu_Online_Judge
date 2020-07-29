#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void)
{
	int n; cin >> n;
	int a, v;
	int max_a, max_v;

	rep(i, n) {
		cin >> a >> v;
		if (i == 0 || v > max_v) {
			max_a = a; max_v = v;
		}
	}
	cout << max_a << " " << max_v << endl;

	return 0; 
}