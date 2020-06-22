#include<iostream>
using namespace std;

bool isInside(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp)
{ 
	double xba = x2 - x1;
	double yba = y2 - y1;
	double xpb = xp - x2;
	double ypb = yp - y2;
	double p1 = xba * ypb - yba * xpb;

	double xcb = x3 - x2;
	double ycb = y3 - y2;
	double xpc = xp - x3;
	double ypc = yp - y3;
	double p2 = xcb * ypc - ycb * xpc;

	double xac = x1 - x3;
	double yac = y1 - y3;
	double xpa = xp - x1;
	double ypa = yp - y1;
	double p3 = xac * ypa - yac * xpa;

	if ((p1 > 0 && p2 > 0 && p3 > 0) || (p1 < 0 && p2 < 0 && p3 < 0)) return 1;
	else return 0;
}

int main(void) {
	double xa, ya, xb, yb, xc, yc, xd, yd;
	(void)scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
	
	bool pd = isInside(xa, ya, xb, yb, xc, yc, xd, yd);
	bool pa = isInside(xb, yb, xc, yc, xd, yd, xa, ya);
	bool pb = isInside(xc, yc, xd, yd, xa, ya, xb, yb);
	bool pc = isInside(xd, yd, xa, ya, xb, yb, xc, yc);

	if (pa || pb || pc || pd) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}