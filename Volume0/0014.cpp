#include<iostream>
using namespace std;

int main(void)
{
	int d; cin >> d;
	long long integral = 0;

	for (int i = 1; i * d <= 600 - d; i++) {
		long long height = (i * d) * (i * d);
		integral = integral + height * d;
	}
	cout << integral << endl;

	return 0;
}