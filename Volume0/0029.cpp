#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
	char s[1000] = "";
	fgets(s, 1000, stdin); s[strlen(s) - 1] = '\0'; //'\n' -> '\0'

	char* word[500];
	word[0] = strtok(s, " ");
	int cnt = 0;
	int i = 0;
	while(1){
		word[i + 1] = strtok(NULL, " ");
		cnt = cnt + 1;
		if (word[i + 1] == NULL) { break; }
		i = i + 1;
	}
	
	int mode = 0, maxmode = 0, len = 0;
	char* mode_word;
	char* maxmode_word;
	char* maxlen_word;
	for (int i = 0; i < cnt; i++){
		for (int j = i + 1; j < cnt; j++) {
			if (strcmp(word[i], word[j]) == 0) {
				mode = mode + 1;
				mode_word = word[i];
			}
		}

		if (maxmode < mode) {
			maxmode = mode;
			maxmode_word = mode_word;
		}

		if (len < strlen(word[i])) {
			len = strlen(word[i]);
			maxlen_word = word[i];
		}
	}
	cout << maxmode_word << " "<< maxlen_word << endl;

	return 0;
}
