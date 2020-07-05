#include<iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)



int main(void) 
{
	rep(i, 5) {
		int s;
		double w, h; (void)scanf("%d,%lf,%lf", &s, &w, &h);
		double bmi = w / (h * h);
		if (bmi >= 25) cout << s << endl;
	}
	return 0;
}