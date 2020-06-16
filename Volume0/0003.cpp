#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n = 1; cin >> n;
	int a[3];
	for (int i = 0; i < n; i++) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		//for (int j = 0; j < 3; j++) cout << a[j] << endl;
		if (a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}