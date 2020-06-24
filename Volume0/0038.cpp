#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	for (int z = 0; z < 8; z++) {
		int a, b, c, d, e;
		(void)scanf("%d,%d,%d,%d,%d", &a, &b, &c, &d, &e);
		int s[5] = {a, b, c, d, e};
		sort(s, s + 5);

		int pair[5] = {};
		int cnt = 1;
		for (int i = 0; i < 5; i++) {
			if (i == 0) { pair[0] = 1; }
			else if (s[i - 1] == s[i]) { cnt = cnt + 1; }
			else { cnt = 1; }
			pair[i] = cnt;
		}
		
		if ((s[0] + 1 == s[1] && s[1] + 1 == s[2] && s[2] + 1 == s[3] && s[3] + 1 == s[4]) ||
			(s[0] == 1 && s[1] == 10 && s[2] == 11 && s[3] == 12 && s[4] == 13)) {
			cout << "straight" << endl;
		}
		else if (pair[3] == 4 || pair[4] == 4) cout << "four card" << endl;
		else if (pair[0] + pair[1] + pair[2] + pair[3] + pair[4] == 5) cout << "null" << endl;
		else {
			sort(pair, pair + 5);
			if (pair[3] == 1 && pair[4] == 2) { cout << "one pair" << endl; }
			else if (pair[3] == 2 && pair[4] == 2) { cout << "two pair" << endl; }
			else if (pair[2] == 1 && pair[3] == 2 && pair[4] == 3) { cout << "three card" << endl; }
			else if (pair[2] == 2 && pair[3] == 2 && pair[4] == 3) { cout << "full house" << endl; }
		}
	}
	return 0;
}