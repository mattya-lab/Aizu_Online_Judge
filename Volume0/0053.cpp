#include<iostream>
using namespace std;

int sumPrimeNumber(int ans, int val)
{
	int cnt = 0;
	for (int i = 2; cnt < val; i++) {
		bool prime = false;
		for (int k = 2; k < i; k++) {
			if (i % k == 0) {
				prime = true; break;
			}
		}
		if (!prime) { ans += i; cnt++; }
	}
	return ans;
}

int main(void)
{
	while (true) {
		int val;  cin >> val; if (val == 0) { break; }
		cout << sumPrimeNumber(0, val) << endl;
	}
	return 0;
}