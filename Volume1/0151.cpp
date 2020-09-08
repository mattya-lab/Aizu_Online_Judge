#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;

using vi = vector<int>;
using vvi = vector<vector<int>>;

void cntnum(vvi v, int n, int col, int row, int dir, int *len) {
	if ( (0 <= col && col < n) && (0 <= row && row < n) ){
		if (v[col][row] == 1) {
                        (*len)++;
			switch (dir) {
			case 0: cntnum(v, n, col - 1, row, dir, len); break;
			case 1: cntnum(v, n, col - 1, row + 1, dir, len); break;
			case 2: cntnum(v, n, col, row + 1, dir, len); break;
			case 3: cntnum(v, n, col + 1, row + 1, dir, len); break;
			case 4: cntnum(v, n, col + 1, row, dir, len); break;
			case 5: cntnum(v, n, col + 1, row - 1, dir, len); break;
			case 6: cntnum(v, n, col, row - 1, dir, len); break;
			case 7: cntnum(v, n, col - 1, row - 1, dir, len); break;
			}
		}
	} 
}

int solve(vvi v, int n) {
	int ans = 0;
	rep(col, n) {
		rep(row, n) {
			rep(dir, 8) {
				int len = 0; 
				cntnum(v, n, col, row, dir, &len);
				if (ans < len)
					ans = len;
			}
		}
	}
	return ans;
}

int main(void) {
	while (true) {
		int n; cin >> n; if (n == 0) break;
		vvi v(n, vi(n));
		rep(i, n) {
			string s; cin >> s;
			rep(j, s.size()) {
				v[i][j] = (s[j] == '1') ? 1 : 0;
			}
		}

		cout << solve(v, n) << endl;

	}
	return 0;
}