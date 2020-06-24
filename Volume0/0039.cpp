#include<iostream>
using namespace std;

int main(void) {
	for (int z = 0; z < 20; z++) {
		char s[100] = ""; cin >> s;
		int ans = 0;
		for (int i = 0; i < strlen(s); i++) {
			switch (s[i]) {

			case 'I':

				switch (s[i + 1]) {
				case 'I':
					if (s[i + 2] == 'I') { ans += 3; i += 2; }
					else { ans += 2; i += 1; }
					break;

				case 'V': ans += 4; i += 1; break;
				case 'X': ans += 9; i += 1; break;

				default: ans += 1; i++;  break;
				}

				break;

			case 'V':
				if (s[i + 1] == 'I') {
					if (s[i + 2] == 'I') {
						if (s[i + 3] == 'I') { ans += 8; i += 3; }
						else { ans += 7; i += 2; }
					}
					else { ans += 6; i += 1; }
				}
				else { ans += 5; }

				break;

			case 'X':
				switch (s[i + 1]) {
				case 'I':
					if (s[i + 2] == 'I') {
						if (s[i + 3] == 'I') { ans += 13; i += 3; }
						else { ans += 12; i += 2; }
					}
					else if (s[i + 2] == 'V') { ans += 14; i += 2; }
					else if (s[i + 2] == 'X') { ans += 19; i += 2; }
					else { ans += 11; i += 1; }
					break;

				case 'V':
					if (s[i + 2] == 'I') {
						if (s[i + 3] == 'I') {
							if (s[i + 4] == 'I') { ans += 18; i += 4; }
							else { ans += 17; i += 3; }
						}
						else { ans += 16; i += 2; }
					}
					else { ans += 15; i += 1; }
					break;

				case 'X':
					if (s[i + 2] == 'X') {
						ans += 30; i += 2;
					}
					else ans += 20; i += 1;
					break;

				case 'L': ans += 40; i += 1; break;
				case 'C': ans += 90; i += 1; break;
				default: ans += 10; break;
				}
				break;

			case 'L':
				if (s[i + 1] == 'X') {
					if (s[i + 2] == 'X') {
						if (s[i + 3] == 'X') { ans += 80; i += 3; }
						else { ans += 70; i += 2; }
					}
					else { ans += 60; i += 1; }
				}
				else { ans += 50; }
				break;

			case 'C': ans += 100; break;

			case 'D': ans += 500; break;

			case 'M': ans += 1000; break;
			}
			cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}