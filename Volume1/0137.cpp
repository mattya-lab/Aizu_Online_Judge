#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;
#define INF (999)

#define n (4)

int main(void) 
{
	int d; cin >> d;
	rep(i, d) {
		int s; cin >> s;
		printf("Case %d:\n", i + 1);
		rep(j, 10) {
			int x = s * s;
			char xs1[2 * n], xs2[2 * n]; 
			sprintf(xs2, "%d", x);
			int xs1_len = 2 * n - strlen(xs2);
			rep(k, xs1_len) { xs1[k] = '0'; }
			xs1[xs1_len] = '\0';
			strcat(xs1, xs2);
			char xs[n];
			rep(k, n) { xs[k] = xs1[k + (n / 2)]; }
			s = atoi(xs);
			cout << s << endl;
		}
	}
	return 0;
}