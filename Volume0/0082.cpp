#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )

int main(void) 
{
	rep(z, 2) {
		int Carriage[8] = { 4, 1, 4, 1, 2, 1, 2, 1 };
		int p[8];
		rep(i, 8) { cin >> p[i]; }

		int c[8];
		bool f = true;
		rep(i, 8) {
			if (p[i] >= 3 && p[i + 2] >= 3 && f) {
				int k = 0;
				for (int j = i; k < 8; j++) {
					c[j % 8] = Carriage[k];
					k++;
				}
				f = false;
			}
		}

		if (f) {
			rep(i, 8) {
				;
			}
		
		}

		rep(i, 8) printf("%d ", c[i]);
		printf("\n");
	}
	return 0;
}