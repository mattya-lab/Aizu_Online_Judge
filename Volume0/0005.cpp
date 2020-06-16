#include<iostream>
using namespace std;

int main() 
{
    double ans = 100000;
	int n; cin >> n;
	double interest = 0.05, benefit = 0;


	for (int i = 0; i < n; i++) {
		benefit = ans * interest;
		ans += benefit;
	}
	
	ans = ans / 1000;
	if (ans >= int(ans)) {
		ans = ans / 10;
		ans = int(ans) + 1;
		ans = ans * 10000;
	}
    
	cout << ans << endl;
	return 0;
}