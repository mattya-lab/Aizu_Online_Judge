#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void) {
	while (true) {
		int q = 0; cin >> q; if (q == -1) { break; }

		double x1 = (double)q / 2;
		double xn = x1 - ((x1 * x1 * x1 - q) / (3 * x1 * x1));
		while(abs(xn * xn * xn - q) > 0.00001 * q){
			xn = xn - ((xn * xn * xn - q) / (3 * xn * xn));
		}
		printf("%lf\n", xn);
	}
	return 0;
}