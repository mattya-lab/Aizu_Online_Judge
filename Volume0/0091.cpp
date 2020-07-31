#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define SIZE 10
#define vecInt vector<int>
#define vecvecInt vector<vector<int>>

void printsq(int sq[][SIZE]);
int checksize(int sq[][SIZE], int row, int col);
bool size1(int sq[][SIZE], int row, int col);
bool size2(int sq[][SIZE], int row, int col);
bool size3(int sq[][SIZE], int row, int col);
void clean(int sq[][SIZE], int i, int j, int size);
void solve(int sq[][SIZE], vecvecInt v, int n);
void Blur(int sq[][SIZE], vecvecInt v, int row, int col, int k, int n);
bool squareallis0(int sq[][SIZE]);

int n = 0;
bool f = true;
vecvecInt r(n, vecInt(3));

void Blur(int sq[][SIZE], vecvecInt v, int row, int col, int k, int n) 
{
	if (!f) return;
	int cs = 0;
	if ((cs = checksize(sq, row, col)) == 0) { return ; }
	int csq[SIZE][SIZE]; rep(i, SIZE) rep(j, SIZE) csq[i][j] = sq[i][j];
	vecvecInt cv; rep(i, v.size()) cv.push_back(v[i]);

	if (cs > 0 && f) {
		vecInt t(3); t[0] = row; t[1] = col; t[2] = cs;
		cv.push_back(t);
		//rep(i, cv.size())cout << cv[i][0] << " " << cv[i][1] << " " << cv[i][2] << endl;
		clean(csq, row, col, cs);
		//printsq(csq);
	}
	
	if (squareallis0(csq)) {
		rep(i, n) {
			r.push_back(cv[i]);
			f = false;
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			Blur(csq, cv, i, j, k + 1, n);
		}
	}
}

int main(void)
{
	int sq[SIZE][SIZE]; 

	rep(i, 10) rep(j, 10) sq[i][j] = 0;

	rep(z, 2) {
		f = true;
		cin >> n;
		rep(i, SIZE) rep(j, SIZE) cin >> sq[i][j];

		vecvecInt v;
		solve(sq, v, n);

		rep(i, r.size()) { cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << endl; }
	}
}

bool size1(int sq[][SIZE], int row, int col)
{
	return (sq[row - 1][col] >= 1 &&
		sq[row][col - 1] >= 1 && sq[row][col] >= 1 && sq[row][col + 1] >= 1 &&
		sq[row + 1][col] >= 1) ? true : false;

}

bool size2(int sq[][SIZE], int row, int col)
{
	return (sq[row - 1][col - 1] >= 1 && sq[row - 1][col] >= 1 && sq[row - 1][col + 1] >= 1 &&
		sq[row][col - 1] >= 1 && sq[row][col] >= 1 && sq[row][col + 1] >= 1 &&
		sq[row + 1][col - 1] >= 1 && sq[row + 1][col] >= 1 && sq[row + 1][col + 1] >= 1) ? true : false;
}

bool size3(int sq[][SIZE], int row, int col)
{
	if (row - 2 < 0 || 9 < row + 2 || col - 2 < 0 || 9 < col + 2) return false;
	return (sq[row - 2][col] >= 1 &&
		sq[row - 1][col - 1] >= 1 && sq[row - 1][col] >= 1 && sq[row - 1][col + 1] >= 1 &&
		sq[row][col - 2] >= 1 && sq[row][col - 1] >= 1 && sq[row][col] >= 1 &&
		sq[row][col + 1] >= 1 && sq[row][col + 2] >= 1 &&
		sq[row + 1][col - 1] >= 1 && sq[row + 1][col] >= 1 && sq[row + 1][col + 1] >= 1 &&
		sq[row + 2][col] >= 1) ? true : false;
}

int checksize(int sq[][SIZE], int row, int col)
{
	if (size3(sq, row, col)) return 3;
	if (size2(sq, row, col)) return 2;
	if (size1(sq, row, col)) return 1;
	return 0;
}


void clean(int sq[][SIZE], int i, int j, int size)
{
	sq[i - 1][j]--;
	sq[i][j - 1]--; sq[i][j]--; sq[i][j + 1]--;
	sq[i + 1][j]--;

	switch (size) {
	case 1:
		break;

	case 2:
		sq[i - 1][j - 1]--; sq[i - 1][j + 1]--;
		sq[i + 1][j - 1]--; sq[i + 1][j + 1]--;
		break;

	case 3:
		sq[i - 2][j]--;
		sq[i - 1][j - 1]--;
		sq[i - 1][j + 1]--;
		sq[i][j - 2]--;
		sq[i][j + 2]--;
		sq[i + 1][j - 1]--;
		sq[i + 1][j + 1]--;
		sq[i + 2][j]--;
		break;
	}
}


void solve(int sq[][SIZE], vecvecInt p, int n)
{
	for (int i = 1; i < SIZE - 1; i++) {
		for (int j = 1; j < SIZE - 1; j++) {
			Blur(sq, p, i, j, 0, n);
		}
	}
}

void printsq(int sq[][SIZE])
{
	cout << "---------------------" << endl;
	rep(i, SIZE) {
		rep(j, SIZE) {
			printf("%d ", sq[i][j]);
		}
		printf("\n");
	}
}

bool squareallis0(int sq[][SIZE]) {
	rep(i, SIZE) {
		rep(j, SIZE) {
			if (sq[i][j] == 1) return false;
		}
	}
	return true;
}