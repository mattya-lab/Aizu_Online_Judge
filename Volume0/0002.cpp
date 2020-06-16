#include<iostream>
using namespace std;

int main() {
	int a, b;  cin >> a >> b;
	int num = a + b;
	int ans = 0;
	while (num != 0) {
		num /= 10;
		ans++;
	}
	cout << ans << endl;
	return 0;
}