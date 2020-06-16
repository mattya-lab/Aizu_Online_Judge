#include<iostream>
#include<math.h>

using namespace std;
#define PI 3.14159265359

int main(void) 
{
	double deg = 90;
	double x = 0, y = 0;
	bool flag = false;
	while (1) 
	{
		double d, a; scanf("%lf,%lf", &d, &a);
		if (d == 0.0 && a == 0.0) { break; }

		if (deg == 90 || deg == -90) {
			x = x;
		}
		else {
			x = x + d * cos(deg * PI / 180);
		}
		if (deg == 180 || deg == 0) {
			y = y;
		}
		else {
			y = y + d * sin((deg) * PI / 180);
		}

		if (flag == false) { 
			flag = true; 
			deg = 90 - a;
		}
		else {
			if (a > 0.0) {
				deg = deg - a;
			}
			else {
				deg = deg + (-1) * a;
			}
		}
	}
	cout << (int)x << " " << (int)y << endl;
}