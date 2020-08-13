#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

#define vecInt vector<int>
#define vecvecInt vector<vecInt>

int main(void) 
{
	while (true) {
		int n; cin >> n; if (n == 0) break;
		vecvecInt a(n + 1, vecInt (n + 1));
		rep(i, n + 1) rep(j, n + 1) a[i][j] = 0;
		rep(i, n) rep(j, n) cin >> a[i][j];
		
		rep(i, n) {
			rep(j, n) {
				a[i][n] += a[i][j];
				a[n][i] += a[j][i];
			}
		}

		rep(i, n) {
			a[n][n] += a[n][i];
		}

		rep(i, n + 1) {
			rep(j, n + 1) {
				printf("%3d ", a[i][j]);
			}
			printf("\n");
		}
		
	}
	return 0;
}