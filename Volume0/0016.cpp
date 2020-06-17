#include<iostream>
#include<math.h>

using namespace std;
#define PI 3.14159265359

int main(void)
{
	double deg = 90;
	double x = 0, y = 0;

	while (1)
	{
		double d, a; (void)scanf("%lf,%lf", &d, &a);
		if (d == 0.0 && a == 0.0) { break; }

		x = x + d * cos(deg * PI / 180);
		y = y + d * sin(deg * PI / 180);

		if (a > 0.0) {
			deg = deg - a;
		}
		else {
			deg = deg + (-1) * a;
		}
	}
	cout << (int)x << " " << (int)y << endl;
	return 0;
}