#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

#define vecInt vector<int>
#define vecvecInt vector<vecInt>

vecvecInt setmap(vecvecInt map, int h, int w);

int main(void) 
{
	while(true){
		int h, w; cin >> h >> w; if (h == 0 && w == 0) break;
		vecvecInt map(h, vecInt(w));
		vecvecInt vis(h, vecInt(w));
		map = setmap(map, h, w);
		rep(i, h) rep(j, w) vis[i][j] = 0;

		int row = 0, col = 0;
		while (true) {
			if (vis[row][col] == 1) {
				cout << "LOOP" << endl;
				break;
			}
			else if (map[row][col] == 0) {
				cout << col << " " << row << endl;
				break;
			}

			vis[row][col]++;

			switch (map[row][col]) {
			case 1: row = row - 1; break;
			case 2: col = col + 1; break;
			case 3: row = row + 1; break;
			case 4: col = col - 1; break;
			}
		}
	}
	return 0;
}

vecvecInt setmap(vecvecInt map, int h, int w) {
	rep(i, h) {
		rep(j, w) {
			char c = ' '; cin >> c;
			// North : 1
			// East  : 2
			// South : 3
			// West  : 4
			if (c == '^') map[i][j] = 1;
			else if (c == '>') map[i][j] = 2;
			else if (c == 'v') map[i][j] = 3;
			else if (c == '<') map[i][j] = 4;
			else { map[i][j] = 0; }
		}
	}
	return map;