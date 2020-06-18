#include<iostream>
using namespace std;

int main(void)
{
	double v; cin >> v;
	double t = v / 9.8;
	double y = 4.9 * t * t;
	cout << y << endl;
	int n;
	for (n = 1; 5 * (n - 1) < y; n++);
	cout << n << endl;
	return 0;
}