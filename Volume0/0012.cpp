#include<iostream>
using namespace std;

int main(void)
{
	double x1, y1, x2, y2, x3, y3, xp, yp;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp;

	double xba = x2 - x1;
	double yba = y2 - y1;
	double xpb = xp - x2;
	double ypb = yp - y2;
	double c1 = xba * ypb - yba * xpb;

	double xcb = x3 - x2;
	double ycb = y3 - y2;
	double xpc = xp - x3;
	double ypc = yp - y3;
	double c2 = xcb * ypc - ycb * xpc;

	double xac = x1 - x3;
	double yac = y1 - y3;
	double xpa = xp - x1;
	double ypa = yp - y1;
	double c3 = xac * ypa - yac * xpa;

	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}