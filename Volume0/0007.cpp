#include<iostream>
using namespace std;

int main() 
{
	double ans = 100000;
	int n; cin >> n;
	double interest = 0.05;

	for (int i = 0; i < n; i++) {
		double benefit = ans * interest;
		ans = ans + benefit;
		int cut = (int)ans % 1000;
		if (cut != 0) {
			ans = (ans - cut) + 1000;
		}
	}
    
	cout << ans << endl;
	return 0;
}