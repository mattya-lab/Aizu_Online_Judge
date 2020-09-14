#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;
#define INF (999)

int main(void) 
{
	rep(z, 4) {
		int a; cin >> a;
		int n = 39;

		a = a % 39;
		if (a == 0) { a = 39; }
		char sa[4];  
		if (a < 10) { sprintf(sa,"3c0%d", a); }
		else { sprintf(sa, "3c%d", a); }
		cout << sa << endl;
	}
	return 0;
}