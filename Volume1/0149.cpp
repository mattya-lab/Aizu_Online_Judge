#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

struct eye_sight { double l, r; };

int main(void) {
	eye_sight e[4];
	rep(i, 4) { e[i].l = 0, e[i].r = 0; }
	rep(i, 4) {
		double l, r;  cin >> l >> r;

		if (l >= 1.1) { e[0].l++; }
		else if(0.6 <= l && l < 1.1){ e[1].l++; }
		else if(0.2 <= l && l < 0.6){ e[2].l++; }
		else { e[3].l++; }

		if (r >= 1.1) { e[0].r++; }
		else if (0.6 <= r && r < 1.1) { e[1].r++; }
		else if (0.2 <= r && r < 0.6) { e[2].r++; }
		else { e[3].r++; }
	}
	rep(i, 4) {
		cout << e[i].l << " " << e[i].r << endl;
	}
	return 0;
}