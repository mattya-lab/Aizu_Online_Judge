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
	bool operator<(const Polygon& p) const {
		return (angle > p.angle);
	}
};

#define PI 3.14159265359
#define vecP vector<Polygon>
vecP BasePoint(vecP p);
vecP getAngle(vecP p);

bool isInside(Polygon p1, Polygon p2, Polygon p3, Polygon pp);

int main(void)
{
	while (true) {
		int ans = 0;
		int n; cin >> n; if (n == 0) { break; }

		vecP p;
		rep(i, n) {
			double x, y; (void)scanf("%lf,%lf", &x, &y);
			p.push_back(Polygon(x, y));
		}

		p = BasePoint(p);
		p = getAngle(p);
		sort(p.begin() + 1, p.end());
		//rep(j, p.size()) { printf("%d :: %lf : %lf : %lf\n", j, p[j].x, p[j].y, p[j].angle); }

		vecP q;
		int k = 0;
		rep(i, p.size()) {
			if (i < 3) { q.push_back(Polygon(p[i].x, p[i].y)); }
			else {
				bool pd = isInside(q[k], q[k + 1], q[k + 2], p[i]);
				bool pa = isInside(q[k + 1], q[k + 2], p[i], q[k]);
				bool pb = isInside(q[k + 2], p[i], q[k], q[k + 1]);
				bool pc = isInside(p[i], q[k], q[k + 1], q[k + 2]);

				if (pa || pb || pc || pd) {
					ans++;
					q.erase(q.begin() + (k + 2));
					k--;
					rep(j, q.size()) {
						printf("%d : %lf : %lf\n", j, q[j].x, q[j].y);
					}
				}
				q.push_back(Polygon(p[i].x, p[i].y));
				k++;
			}
		}

		cout << ans << endl;
	}
	return 0;
}

bool isInside(Polygon p1, Polygon p2, Polygon p3, Polygon pp) {
	double xba = p2.x - p1.x;
	double yba = p2.y - p1.y;
	double xpb = pp.x - p2.x;
	double ypb = pp.y - p2.y;
	double v1 = xba * ypb - yba * xpb;

	double xcb = p3.x - p2.x;
	double ycb = p3.y - p2.y;
	double xpc = pp.x - p3.x;
	double ypc = pp.y - p3.y;
	double v2 = xcb * ypc - ycb * xpc;

	double xac = p1.x - p3.x;
	double yac = p1.y - p3.y;
	double xpa = pp.x - p1.x;
	double ypa = pp.y - pp.y;
	double v3 = xac * ypa - yac * xpa;

	if ((v1 > 0 && v2 > 0 && v3 > 0) || (v1 < 0 && v2 < 0 && v3 < 0)) return 1;
	else return 0;
}

vecP getAngle(vecP p) {
	for (int i = 1; i < p.size(); i++) {
		double a = p[i].x - p[0].x;
		double b = p[i].y - p[0].y;
		if (a == 0.0) { p[i].angle = 90.0; }
		else if (b == 0.0) { p[i].angle = 0.0; }
		else { p[i].angle = atan(b / a) * (180.0 / PI); }
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