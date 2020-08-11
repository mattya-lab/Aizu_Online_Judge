#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

int main(void) 
{
	int n; cin >> n;
	rep(i, n) {
		char s[255] = " "; 
		fgets(s, 255, stdin); s[strlen(s) - 1] = '\0';
		char* ptr[255];
		int len = 0;
		ptr[0] = strtok(s, " ");
		for (int j = 1; ptr[j - 1] != NULL; j++) { ptr[j] = strtok(NULL, " "); len++; }

		rep(j, len) {
			if (strcmp(ptr[j], "Hoshino") == 0) {
				strcpy(ptr[j], "Hoshina");
			}
			printf("%s ", ptr[j]);
		}
		printf("\n");
	}
	return 0;
}