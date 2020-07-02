#include<iostream>
#include<vector>
using namespace std;
#define vInt vector<int>

vInt findPrimeNumber(vInt a, int val)
{
	for (int i = 2; i < val; i++) {
		bool prime = false;		
		for (int k = 2; k < i; k++) {
			if (i % k == 0) {
				prime = true; break;
			}
		}
		if (!prime) { a.push_back(i); }
	}
	return a;
}

bool checkPrimeNumber(int n)
{
	bool prime = false;
	for (int k = 2; k < n; k++) {
		if (n % k == 0) {
			prime = true; break;
		}
	}
	return (prime) ? false : true;
}

int main(void)
{
	while(true){
		int val;  cin >> val; if (val == 0) { break; }
		int ans = 0;
		vInt a;

		if (val % 2 == 1 && val == 2) { cout << ans << endl; }
		else { a = findPrimeNumber(a, val); }

		for (int i = 0; i < a.size() / 2 + 1; i++) {
			int n = val - a[i];
			if (checkPrimeNumber(n)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
