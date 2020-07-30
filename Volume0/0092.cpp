#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define vecInt vector<int>
#define vecvecInt vector<vector<int>>

int solve(vecvecInt v);
bool checkSquareSumIs0(vecvecInt v, int cur_row, int cur_col, int col, int row);

int main(void)
{
	while (true) {
		int n;  cin >> n; if (n == 0) break;
		vecvecInt v(n, vecInt(n));
		rep(i, n) {
			char s[255] = " "; (void)scanf("%s", s);
			rep(j, n) { v[i][j] = (s[j] == '*') ? 1 : 0; }
		}
		cout << solve(v) << endl;

	}
	return 0;
}


int solve(vecvecInt v)
 {
	int ans = 0;
	rep(i, v.size()) {
		rep(j, v[i].size()) {
			if (v[i][j] == 0) {
				int len = 0;
				bool f = true;;
				for (int k = j; k < v[i].size(); k++) { 
					if (v[i][k] == 1) { break; }
					len++;
				}

				rep(k, len) {
					if (v[i + k][j] == 1 || i + len > v[i].size() - 1) { f = false; break; }
				}

				if (f) {
					int len_row = i + len - 1;
					int len_col = j + len - 1;
					
					if (checkSquareSumIs0(v, i, j, len_row, len_col)) { ans = max(ans, len); }
				}
			}
		}
	}
	return ans;
}

bool checkSquareSumIs0(vecvecInt v, int cur_row, int cur_col, int row, int col) 
{
	for (int i = cur_row; i <= row; i++) {
		for (int j = cur_col; j <= col; j++) {
			if (v[i][j] == 1) { return false; }
		}
	}
	return true;
}
