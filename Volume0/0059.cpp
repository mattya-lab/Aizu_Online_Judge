#include<iostream>
using namespace std;

int main(void) {
	for (int z = 0; z < 3; z++) {
		double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
		cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2;


		if ((ya1 <= yb1 && yb1 <= ya2) && (xa1 <= xb2 && xb2 <= xa2)) {
			cout << "YES" << endl;
		}
		else if ((ya1 <= yb2 && yb2 <= ya2) && (xa1 <= xb2 && xb2 <= xa2)) {
			cout << "YES" << endl;
		}
		else if ((ya1 <= yb1 && yb1 <= ya2) && (xa1 <= xb1 && xb1 <= xa2)) {
			cout << "YES" << endl;
		}
		else if ((ya1 <= yb2 && yb2 <= ya2) && (xa1 <= xb2 && xb2 <= xa2)) {
			cout << "YES" << endl;
		}

		else if ((yb1 <= ya1 && ya1 <= yb2) && (xb1 <= xa1 && xa1 <= xb2)) {
			cout << "YES" << endl;
		}
		else if ((yb1 <= ya2 && ya2 <= yb2) && (xb1 <= xa2 && xa2 <= xa2)) {
			cout << "YES" << endl;
		}
		else if ((yb1 <= ya1 && ya1 <= yb2) && (xb1 <= xa2 && xa2 <= xa2)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}