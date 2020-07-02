#include<iostream>
using namespace std;

int main(void) {
	for (int z = 0; z < 2; z++) {
		int n; cin >> n;
		int sum = 1;
		for (int i = 1; i <= n; i++) { sum = sum + (i);}
		cout << sum << endl;
	}
	return 0;
}