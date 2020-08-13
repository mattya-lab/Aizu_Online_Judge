#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

int main(void) 
{
	int n = 0; cin >> n;
	rep(i, n) {
		int b1 = 0, b2 = 0, b3 = 0;
		int out = 0;
		int ans = 0;
		while(out < 3) {
			char s[10]; cin >> s;
			if (strcmp(s, "HIT") == 0) {
				if (b1 == 0) b1 = 1;
				else { // (b1 == 1)
					b1 = 1;
					if (b2 == 0) b2 = 1;
					else { // (b2 == 1)
						b2 = 1;
						if (b3 == 0) b3 = 1;
						else { // (b3 == 1)
							b3 = 1;
							ans++;
						}
					}
				}
			}
			else if (strcmp(s, "OUT") == 0) {
				out = out + 1;
			}
			else { // HOMERUN
				ans++;
				if (b1 == 1) ans++;
				if (b2 == 1) ans++;
				if (b3 == 1) ans++;
				b1 = 0;
				b2 = 0;
				b3 = 0;
			}
		}
		cout << ans << endl;
	}

	return 0;
}