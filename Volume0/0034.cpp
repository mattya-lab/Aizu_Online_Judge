#include<iostream>
using namespace std;

int main(void) {
	for (int z = 0; z < 3; z++) {
		int l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;
		int v1, v2;
		(void)scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &v1, &v2);
		int l[10] = { l1, l2, l3, l4, l5, l6, l7, l8, l9, l10 };

		double distance = (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10); 
		double hour = distance / (v1 + v2);

		int cross = 0;
		int block = 1;
		for (int i = 0; i < 10; i++) {
			cross = cross + l[i];
			if (cross >= v1 * hour) {
				break;
			}
			block++;
		}
		cout << block << endl;
	}
	return 0;
}