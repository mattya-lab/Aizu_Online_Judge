#include<iostream>
using namespace std;

int main(void) 
{
	double a;
	double high;
	double low;

	for (int i = 0; i < 5; i++) {
		cin >> a;
		if (i == 0) {
			high = a; low = a;
		}

		if (a > high) {
			high = a;
		}
		if (a < low) {
			low = a;
		}
	}
	cout << high - low << endl;
	return 0;
}