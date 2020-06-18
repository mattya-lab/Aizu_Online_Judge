#include<iostream>
using namespace std;

int main(void)
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		double grad_ab = (y2 - y1) / (x2 - x1);
		double grad_cd = (y4 - y3) / (x4 - x3);

		if (grad_ab == grad_cd) printf("yes\n");
		else printf("no\n");
	}
 	return 0;