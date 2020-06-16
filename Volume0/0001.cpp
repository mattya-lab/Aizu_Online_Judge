#include<iostream>
using namespace std;

int main(void) {
	int st = 0, nd = 0, rd = 0;
	for (int i = 0; i < 10; i++) {
		int tmp, m; cin >> m;
		if (m > st) {
			tmp = st;
			st = m; 
			m = tmp;
		}
		if (m > nd) {
			tmp = nd;
			nd = m;
			m = tmp;
		}
		if (m > rd) {
			tmp = rd;
			rd = m;
			m = tmp;
		}
	}
	printf("%d\n", st);
	printf("%d\n", nd);
	printf("%d\n", rd);
}