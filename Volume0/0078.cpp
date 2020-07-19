#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void) {
	while (true) {
		int n; cin >> n; if (n == 0) { break; }
		vector<vector<int>> p(n, vector<int>(n)); rep(i, n) { rep(j, n) { p[i][j] = 0; } }
		int y = (n) / 2 + 1;
		int x = (n )/ 2;
		int num = 1;
		p[y][x] = num;

		while (num  < (n)*(n)) {
			y = y + 1;
			x = x + 1;
			if (y > n - 1) { y = 0; }
			if (x > n - 1) { x = 0; }

			if (p[y][x] != 0) {
				y = y + 1; 
				x = x - 1;  
				if (y > n - 1) { y = 0; }
				if (x < 0) { x = n - 1; }
				if (x > n - 1) { x = 0; }
			}

			num = num + 1;
			p[y][x] = num;
		}

		rep(i, n) { rep(j, n) { cout << p[i][j] << " "; } cout << endl; }
	}
	return 0;
}