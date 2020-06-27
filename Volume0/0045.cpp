#include<iostream>
using namespace std;

int main(void) {
	int n = 3;
	int sum = 0;
	int num = 0;
	double ave = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		(void)scanf("%d,%d", &a, &b);
		sum = sum + a * b;
		num = num + b;
	}
	ave = (double)num / n;
	if (ave - int(ave) > 0.4) {
		ave = int(ave) + 1;
	}
	cout << sum << " " << ave << endl;
}