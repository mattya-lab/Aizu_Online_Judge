#include<iostream>
using namespace std;

int main(void) 
{
	int rectangle = 0;
	int rhombus = 0;

	for (int l = 0; l < 4; l++) {
		int a, b, c;
		(void)scanf("%d,%d,%d", &a, &b, &c);

		if (a + b > c) {
			if (a == b) {
				rhombus++;
			}
			if(a * a + b * b == c * c) rectangle++;
		}
	}
	cout << rectangle << endl;
	cout << rhombus << endl;
	return 0;
}