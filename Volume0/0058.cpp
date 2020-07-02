#include<iostream>
using namespace std;

int main(void) {
	for (int z = 0; z < 4; z++) {
		double xa, ya, xb, yb, xc, yc, xd, yd;
		cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

		double x_ab = xb - xa;
		double y_ab = yb - ya;
		double x_cd = xd - xc;
		double y_cd = yd - yc;
	
		if (x_ab == 0 && y_cd == 0) { cout << "YES" << endl; }
		else if (y_ab == 0 && x_cd == 0) { cout << "YES" << endl; }
		else {
			double grad_ab = (yb - ya) / (xb - xa);
			double grad_cd = (yd - yc) / (xd - xc);
			if (grad_ab * grad_cd == -1) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}