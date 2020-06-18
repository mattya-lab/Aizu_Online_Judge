#include<iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 2; i++) {
		long long a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		double inverse = a * e - b * d;
		double x = 1 / inverse * (c * e + (-1) * b * f);
		double y = 1 / inverse * ((-1) * c * d + a * f);
		cout << x << " " << y << endl;
	}
	return 0;
}