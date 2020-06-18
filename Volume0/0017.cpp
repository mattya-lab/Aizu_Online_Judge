#include<iostream>
#include<string.h>

int main(void)
{
	char s[80 + 1] = "", t[80 + 1] = "";
	fgets(s, 80 + 1, stdin); s[strlen(s) - 1] = '\0';
	int n = 0;

	for (int i = 0; i < 26; i++) {
		for(int j = 0; j < strlen(s); j++){
			if (s[j] == ' ') { break; }
			t[j] = (s[j] - 'a' + i) % 26 + 'a';
		}
		if (strcmp(t, "the") == 0 || strcmp(t, "this") == 0 || strcmp(t, "that") == 0 ) {
			n = i;
			break;
		}
	}
	
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') t[i] = ' ';
		else if (s[i] == '.') t[i] = '.';
		else { t[i] = (s[i] - 'a' + n) % 26 + 'a'; } 
	}
	printf("%s", t);
	
	return 0;
}
