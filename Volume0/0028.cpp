#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
	int n = 12;
	int a[100];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	sort(a, a + n);

	int m = 0;
	int mode_idx = 0;

	for (int i = 0; i < n - 1; i++) {
		m = m + 1;
		if(a[i] != a[i + 1]){
			mode_idx = max(m, mode_idx);
			m = 0;
		}
	}

	m = 0;
	for (int i = 0; i < n - 1; i++) {
		m = m + 1;
		if (a[i] != a[i + 1]) {
			if (m == mode_idx) { printf("%d\n", a[i]); }
			m = 0;
		}
	}
	
	return 0;
}