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

		if (d > ra + rb)  cout << "0" << endl;
		else if (d == ra + rb || ra == d + rb || rb == d + ra) cout << "1" << endl;
		else if (rb < d + ra) cout << "2" << endl;
		else cout << "-2" << endl;
	}
        return 0;
}