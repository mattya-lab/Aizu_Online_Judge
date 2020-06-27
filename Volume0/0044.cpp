#include<iostream>
using namespace std;

int main(void) {
	int n; cin >> n;
	int s = 0, t = 0;

	for (int k = n - 1; k >= 3; k--) {
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (k % i == 0) {
				cnt++;
			}
		}
		if (cnt == 2) { s = k; break; }
	}

	for (int k = n + 1; k < 50000; k++) {
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (k % i == 0) {
				cnt++;
			}
		}
		if (cnt == 2) { t = k; break; }
	}

	cout << s << " " << t <<endl;
	return 0;
}