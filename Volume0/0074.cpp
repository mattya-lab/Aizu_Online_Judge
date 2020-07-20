#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void) {
	while (true) {
		int t, h, s; cin >> t >> h >> s;
		if (t == -1 && h == -1 && s == -1) { break; }
		int sum = t * 60 * 60 + h * 60 + s;

		int rs = 2 * 60 * 60 - sum;
		int vs = 3 * rs;

		int rt = rs / (60 * 60);
		int rh = rs % (60 * 60);
		rh = rh / 60;
		rs = rs % 60;

		int vt = vs / (60 * 60);
		int vh = vs % (60 * 60);
		vh = vh / 60;
		vs = vs % 60;
		cout << rt << " " << rh << " " << rs << endl;
		cout << vt << " " << vh << " " << vs << endl;
	}
	return 0;
}