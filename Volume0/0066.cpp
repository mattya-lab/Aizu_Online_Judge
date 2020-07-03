#include<iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

bool TicTacToe(int a[][3], int t) {
	if (a[1][1] == t) {
		if ((a[0][0] == t && a[2][2] == t) || (a[2][0] == t && a[0][2]) == t) return true;
	}

	if (a[0][0] == t && a[0][1] == t && a[0][2] == t) return true;
	else if (a[0][0] == t && a[1][0] == t && a[2][0] == t) return true;
	else if (a[1][0] == t && a[1][1] == t && a[1][2] == t) return true;
	else if (a[0][1] == t && a[1][1] == t && a[0][2] == t) return true;
	else if (a[2][0] == t && a[2][1] == t && a[2][2] == t) return true;
	else if (a[0][2] == t && a[1][2] == t && a[2][2] == t) return true;
	else return false;
}

int main(void)
{
	for (int z = 0; z < 3; z++) {
		char s[9 + 1] = ""; cin >> s;
		int a[3][3];
		int row = 0, col = 0;
		rep(i, strlen(s)){
			if (s[i] == 'o') { a[row][col] = 1; }
			else if (s[i] == 'x') { a[row][col] = -1; }
			else { a[row][col] = 0; }
			col++;
			if (col % 3 == 0) {
				row = row + 1;  col = 0;
			}
		}
		
		if (TicTacToe(a, 1)) cout << 'o' << endl;
		else if(TicTacToe(a, -1)) cout << 'x' << endl;
		else { cout << 'd' << endl; }

	}
        return 0;
}