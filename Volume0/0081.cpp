#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void)
{
	rep(i, 3) {
		double x1, y1, x2, y2, xq, yq;
		(void)scanf("%lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &xq, &yq);

		double iy = y2 - y1;
		double ix = x2 - x1;

		// y = a * x + b
		double a = (ix == 0.0) ? 0.0 : iy / ix;
		double b = y1 - a * x1;
		double x, y;

		if (a != 0.0) {
			// y = a2 * x + b2
			double a2 = (-1) / a;
			double b2 = yq - a2 * xq;

			double p = (a == a2) ? 0.0 : (b2 - b) / (a - a2);
			double q = a * p + b;

			//p = (x + x3) / 2;
			x = 2 * p - xq;
			//q = (y + y3) / 2;
			y = 2 * q - yq;
		}
		else {
			double p = (ix == 0.0) ? 0.0 : xq;
			double q = (iy == 0.0) ? 0.0 : yq;

			if (p == 0.0) {
				x = 2 * p - xq; y = yq;
			}
			else if (q == 0.0) {
				x = xq; y = 2 * q - yq;
			}

		}
		printf("%lf %lf\n", x, y);
	}
	return 0;

}