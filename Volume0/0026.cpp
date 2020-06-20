#include<iostream>
#include<algorithm>
using namespace std;

void paint_ink(int a[][10], int x, int y, int s)
{
	a[x][y]++;
	a[x - 1][y] = (x - 1 >= 0) ? a[x - 1][y] + 1 : a[x - 1][y];
	a[x + 1][y] = (x + 1 <= 9) ? a[x + 1][y] + 1 : a[x + 1][y];
	a[x][y - 1] = (y - 1 >= 0) ? a[x][y - 1] + 1 : a[x][y - 1];
	a[x][y + 1] = (y + 1 <= 9) ? a[x][y + 1] + 1 : a[x][y + 1];

	switch (s) {
	case 1:
		break;

	case 2:
		a[x - 1][y - 1] = (x - 1 >= 0 && y - 1 >= 0) ? a[x - 1][y - 1] + 1 : a[x - 1][y - 1];
		a[x - 1][y + 1] = (x - 1 >= 0 && y + 1 <= 9) ? a[x - 1][y + 1] + 1 : a[x - 1][y + 1];
		a[x + 1][y - 1] = (x + 1 <= 9 && y - 1 >= 0) ? a[x + 1][y - 1] + 1 : a[x + 1][y - 1];
		a[x + 1][y + 1] = (x + 1 <= 9 && y + 1 <= 9) ? a[x + 1][y + 1] + 1 : a[x + 1][y + 1];

		break;

	case 3:
		a[x - 2][y] = (x - 2 >= 0) ? a[x - 2][y] + 1 : a[x - 2][y];
		a[x + 2][y] = (x + 2 <= 9) ? a[x + 2][y] + 1 : a[x + 2][y];
		a[x][y - 2] = (y - 2 >= 0) ? a[x][y - 2] + 1 : a[x][y - 2];
		a[x][y + 2] = (y + 2 <= 9) ? a[x][y + 2] + 1 : a[x][y + 2];

		a[x - 1][y - 1] = (x - 1 >= 0 && y - 1 >= 0) ? a[x - 1][y - 1] + 1 : a[x - 1][y - 1];
		a[x - 1][y + 1] = (x - 1 >= 0 && y + 1 <= 9) ? a[x - 1][y + 1] + 1 : a[x - 1][y + 1];
		a[x + 1][y - 1] = (x + 1 <= 9 && y - 1 >= 0) ? a[x + 1][y - 1] + 1 : a[x + 1][y - 1];
		a[x + 1][y + 1] = (x + 1 <= 9 && y + 1 <= 9) ? a[x + 1][y + 1] + 1 : a[x + 1][y + 1];
		break;
	}
}

int main(void)
{
	int n = 6;

	int a[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			a[i][j] = 0;
		}
	}

	int x, y, s;

	for (int i = 0; i < n; i++) {
		(void)scanf("%d, %d, %d", &x, &y, &s);
		paint_ink(a, x, y, s);
	}

	int ans = 0, res = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (a[i][j] == 0) { ans++; }
			if (res < a[i][j]) { res = max(res, a[i][j]); }
		}
	}
	cout << ans << endl;
	cout << res << endl;

	return 0;
}
