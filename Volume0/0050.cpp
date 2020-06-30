#include<iostream>
using namespace std;

int main() {
	char s[256]; 

	fgets(s, 256, stdin); s[strlen(s) - 1] = '\0';
	char* word[128];

	int len = 0;
	word[0] = strtok(s, " ");
	for (unsigned int i = 1; word[i - 1] != NULL; i++) { word[i] = strtok(NULL, " "); len++; }

	for (int i = 0; i < len; i++) {
		if (strncmp(word[i], "apple", 5) == 0) { strcpy(word[i], "peach"); }
		else if (strncmp(word[i], "peach", 5) == 0) { strcpy(word[i], "apple"); }
	}
	for (int i = 0; i < len; i++) { cout << word[i] << " "; }
	printf("\n");
	return 0;
}