#include<iostream>

using namespace std;

int main(void)
{
	for (int z = 0; z < 3; z++) {
		double a; cin >> a;

		double s = a;
		for (int i = 2; i <= 10; i++) { 
			if (i % 2 == 0) { a = a * 2; }
			else { a = a / 3; }

			s = s + a;
		}
		printf("%.8lf\n", s);
	}
	return 0;
}