#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )
#define N (1023)

int main(void) 
{
	rep(z, 2) {
		char s[N] = "";;
		fgets(s, N, stdin); s[strlen(s) - 1] = '\0';
		char word[N] = "";
		int k = 0;

		rep(i, strlen(s)) {
			if (s[i] == ',' || s[i] == ' ' || s[i] == '.') {
				if(2 <  k && k < 7) cout << word << " ";
				rep(j, k) word[j] = '\0';
				k = 0;
			}
			else {
				word[k] = s[i];
				k++;
			}
		}
		printf("\n");
	}
	return 0;
}