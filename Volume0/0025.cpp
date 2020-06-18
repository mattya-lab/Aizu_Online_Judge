#include<iostream>
using namespace std;

int main(void)
{
	for (int l = 0; l < 2; l++) {
		int a[4 + 1], b[4 + 1];
		int hit = 0, blow = 0;
		for (int i = 0; i < 4; i++) { cin >> a[i]; }
		for (int i = 0; i < 4; i++) { cin >> b[i]; }
		for (int i = 0; i < 4; i++) {
			if (b[i] == a[i]) hit++;
			for (int j = 0; j < 4; j++) {
				if (j == i) continue;
				else if (a[j] == b[i]) blow++;
			}
		}
		cout << hit << " " << blow << endl;
	}
	return 0;
}