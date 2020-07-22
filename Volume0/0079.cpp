#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

struct Polygon {
	double x;
	double y;
	double angle;

	Polygon(double s, double t) {
		x = s;
		y = t;
		angle = 0.0;
	}

	bool operator<(const Polygon &p) const{
		return (angle > p.angle);
	}
};

#define PI 3.14159265359
#define vecP vector<Polygon>
vecP BasePoint(vecP p);
vecP getAngle(vecP p);
double PolygonArea(vecP p);

int main(void)
{
	int n = 5;
	vecP p;
	rep(i, n) {
		double x, y; (void)scanf("%lf,%lf", &x, &y);
		p.push_back(Polygon(x, y));
	}
	p = BasePoint(p);
	p = getAngle(p);
	sort(p.begin() + 1, p.end());
	printf("%lf\n", PolygonArea(p));
	return 0;
}

double PolygonArea(vecP p) {
	double sum = 0.0;
	for (int i = 1; i < p.size() - 1; i++) {
		double a = sqrt((p[i].x - p[0].x) * (p[i].x - p[0].x) + (p[i].y - p[0].y) * (p[i].y - p[0].y));
		double b = sqrt((p[i + 1].x - p[0].x) * (p[i + 1].x - p[0].x) + (p[i + 1].y - p[0].y) * (p[i + 1].y - p[0].y));
		double c = sqrt((p[i + 1].x - p[i].x) * (p[i + 1].x - p[i].x) + (p[i + 1].y - p[i].y) * (p[i + 1].y - p[i].y));
		double z = (a + b + c) / 2;
		sum += sqrt(z * (z - a) * (z - b) * (z - c));
	}
	
	return sum;
}

vecP getAngle(vecP p) {
	for (int i = 1; i < p.size(); i++) {
		double a = p[i].x - p[0].x;
		double b = p[i].y - p[0].y;
		if (a == 0.0) { p[i].angle = 90.0; }
		else if (b == 0.0) { p[i].angle = 0.0; }
		else { p[i].angle = atan(b / a) * (180 / PI); }
	}
	return p;
}

vecP BasePoint(vecP p) {
	double x_min = p[0].x;
	for (int i = 1; i < p.size(); i++) {
		if (p[i].x < x_min) {
			Polygon tmp = p[i];
			p[i] = p[0];
			p[0] = tmp;
		}
	}
	p[0].angle = 0.0;
	return p;
}