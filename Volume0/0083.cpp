include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void) 
{
	rep(z, 3) {
		int y, m, d; cin >> y >> m >> d;

		if (1868 <= y && y <= 1912) {
			if (1868 == y && m <= 9 && d <= 8 - 1) { 
				cout << "pre-meiji" << endl;
			}
			else if (y == 1912 && m >= 7 && d > 29) {
				if (y == 1912) { y = 1; }
				else { y = y - 1982 + 1; }
				cout << "taisho" <<  " " << y << " " << m << " " << d << endl;
			}
			else {
				if (y == 1868) y = 1;
				else y = y - 1868 + 1;
				cout << "meiji" << " " << y << " " << m << " " << d << endl;
			}
		}
		else if (1212 + 1 <= y && y <= 1926) {
			if (y == 1926 && m == 12 && d > 24) {
				y = 1;
				cout << "showa" << " " << y << " " << m << " " << d << endl;
			}
			else {
				y = y - 1212 + 1;
				cout << "taisho" << " " << y << " " << m << " " << d << endl;
			}
		}
		else if (1926 + 1 <= y && y <= 1989) {
			if (y == 1989 && m >= 1 && d > 7) {
				y = 1;
				cout << "heisei" << " " << y << " " << m << " " << d << endl;
			}
			else {
				y = y - 1926 + 1;
				cout << "heisei" << " " << y << " " << m << " " << d << endl;
			}
		}
		else {
			if (y < 1868) { 
				cout << "pre-meiji" << endl;
			}
			else /* (y <= 1989 && m <= 1 && d <= 8) */{
				if (y == 1989) y = 1;
				else  y = y - 1989 + 1;
				cout << "heise" <<  " " << y << " " << m << " " << d << endl;
			}
		}
	}
	return 0;
}