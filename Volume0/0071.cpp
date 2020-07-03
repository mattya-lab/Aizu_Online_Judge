#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

void print(int g[][8]);
void Explode(int g[][8], int x, int y) 
{
	if (g[y][x] == 1) {
		g[y][x] = 0; 
		if (0 <= x - 3) { Explode(g, x - 3, y); }
		if (0 <= x - 2) { Explode(g, x - 2, y); }
		if (0 <= x - 1) { Explode(g, x - 1, y); }
		if (x + 1 < 8) { Explode(g, x + 1, y); }
		if (x + 2 < 8) { Explode(g, x + 2, y); }
		if (x + 3 < 9) { Explode(g, x + 3, y); }

		if (0 <= y - 3) { Explode(g, x, y - 3); }
		if (0 <= y - 2) { Explode(g, x, y - 2); }
		if (0 <= y - 1) { Explode(g, x, y - 1); }
		if (y + 1 < 8) { Explode(g, x, y + 1); }
		if (y + 2 < 8) { Explode(g, x, y + 2); }
		if (y + 3 < 8) { Explode(g, x, y + 3); }
	}
}

int main(void) 
{
	int n; cin >> n;
	int Data = 1;
	for (int i = 0; i < n; i++) {
		int g[8][8];
		rep(i, 8) {
			char s[8 + 1] = ""; cin >> s;
			rep(j, 8) {
				g[i][j] = s[j] - '0';
			}
		}

		int x; cin >> x;
		int y; cin >> y;

		cout << "Data " << Data << ":" << endl;
		Explode(g, x - 1, y - 1);
		print(g);
	}
}

void print(int g[][8]) {
	rep(i, 8) {
		rep(j, 8) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}