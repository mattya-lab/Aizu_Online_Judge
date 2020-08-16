#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define vecInt vector<int>


bool checkGoThroughGate(int d, int w, int h, int r) {
	double e = sqrt((double)(d * d + w * w));
	if (2 * r > e) {
			return true;
	}
	return false;
}

int main(void) {
	while (true) {
		int d, w, h; cin >> d >> w >> h; if (d == 0 && w == 0 && h == 0) { break; }
		int n; cin >> n;

		vecInt r(n);
		rep(i, n) {
			cin >> r[i];
			if (checkGoThroughGate(d, w, h, r[i])) cout << "OK" << endl; 
			else cout << "NA" << endl;
		}
	}
}