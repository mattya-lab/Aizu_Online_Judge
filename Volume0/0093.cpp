#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)


bool LeapYear(int x) {
	if (x % 4 == 0) {
		if (x % 400 == 0) return true;
		else if(x % 100 == 0) return false;
		else { return true; }
	}
	return false;
}

int main(void) 
{
	while (true) {
		int a, b; cin >> a >> b; if (a == 0 && b == 0) { break; }
		bool f = false;
		for (int i = a; i <= b; i++) {
			if (LeapYear(i)) {
				cout << i << endl;
				f = true;
			}
		}
		if (!f) { cout << "NA" << endl; }
	}
}