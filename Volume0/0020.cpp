#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
	char s[200 + 1] = "";
	fgets(s, 200, stdin); s[strlen(s)] = s[strlen(s) - 1] = '\0';

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') { printf("%c", s[i]); }
		else if (s[i] == '.') { printf("%c", s[i]); }
		else { printf("%c", toupper(s[i]));  }
	}
	return 0;
}