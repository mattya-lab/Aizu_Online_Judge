#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )
#define PI 3.14159265359

int main(void) {
	while (true) {
		int n; cin >> n; if (n == -1) { break; }
		double x = 0, y = 0;
		double deg = 90;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				x = x + cos(0 * PI / 180);
			}
			else if (i == 1) {
				x = x + cos(deg * PI / 180);
				y = y + sin(deg * PI / 180);
			}
			else {
				double a = x;
				double b = y;
				double c = sqrt(x * x + y * y);
				double cosdeg2 = (c * c + b * b - a * a) / (2 * b * c);
				double deg2 = acos(cosdeg2) * 180 / PI;
				
				if (0 < x && 0 < y) {
					deg = (180 - deg2 - 90) + 90;
				}
				else if (x < 0 && 0 < y) {
					deg = (180 - (90 - deg2)) + 90;
				}
				x = x + cos(deg * PI / 180);
				y = y + sin(deg * PI / 180);
			}
		}
		cout << x << endl;
		cout << y << endl;
	}
	return 0;
}