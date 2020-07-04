#include<iostream>
#include<math.h>
using namespace std;

int main(void) 
{
	while (true) {
		double x, h; cin >> x >> h;
		if (x == 0 && h == 0) break;
		double t = sqrt(x / 2 * x / 2 + h * h);
		double s = (x * x) + (4.0 * 1/2 * x * t);
		printf("%lf\n", s);
	}
	return 0;
}