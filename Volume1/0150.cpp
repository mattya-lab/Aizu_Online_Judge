#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

bool check_prime(int v) {
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (v % i == 0) { cnt++; }
	}
	return (cnt == 2) ? true : false;
}

int main(void) {
	while(true) {
		int n; cin >> n; if (n == 0) break;
		int p;
		for (int q = n; q >= 5; q--) {
			if (check_prime((p = q - 2)) && check_prime((q))) {
				cout << p << " " << q << endl;
				break;
				
			}
		}
	}
}