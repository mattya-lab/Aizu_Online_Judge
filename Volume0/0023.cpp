#include<iostream>
#include<math.h>
using namespace std;

int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double xa, ya, ra, xb, yb, rb;
		cin >> xa >> ya >> ra >> xb >> yb >> rb;

		double xd = xb - xa;
		double yd = yb - ya;

		double d = sqrt(xd * xd + yd * yd);
		double r1, r2;
		if (ra > rb) {
			r1 = ra;
			r2 = rb;
		}
		else {
			r1 = rb;
			r2 = ra;
		}
		if (d > r1 + r2)  cout << "0" << endl;
		else if ((r1 - r2 < d && d < r1 + r2) || (d == r1 + r2 || r1 == d + r2 || r2 == d + r1)) cout << "1" << endl;
		else if (rb < d + ra) cout << "2" << endl;
		else cout << "-2" << endl;
	}
	return 0;
}