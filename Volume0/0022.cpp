#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int ans;
	int sum[5000]; for (int i = 0; i < 5000; i++) { sum[i] = 0; }
	for (int l = 0; l < 3; l++) {
		int n; cin >> n;
		if (n == 0) break;
		int a; cin >> a;
		sum[0] = a;
		for (int i = 1; i < n; i++) {
			cin >> a;
			sum[i] = max(a, sum[i - 1] + a);
		}
		sort(sum, sum + n);
		ans = sum[n - 1];
		
		cout << ans << endl;
	}
	
 	return 0;
}