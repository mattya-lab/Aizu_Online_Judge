#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		double a = x1 - x2;
		double b = y1 - y2;
		double c = x2 - x3;
		double d = y2 - y3;

		double x1_vec = x1 * x1 + y1 * y1;
		double x2_vec = x2 * x2 + y2 * y2;
		double x3_vec = x3 * x3 + y3 * y3;

		double matrix = (a * d - b * c);

		double p1 = 1 / (2 * matrix) * (d * (x1_vec - x2_vec) + (-1) * b * (x2_vec - x3_vec));
		double p2 = 1 / (2 * matrix) * ((-1) * c * (x1_vec - x2_vec) + a * (x2_vec - x3_vec));
		double r = sqrt((x1 - p1) * (x1 - p1) + (y1 - p2) * (y1 - p2));
		cout << p1 << " " << p2 << " " << r << endl;
	}
	return 0;
}