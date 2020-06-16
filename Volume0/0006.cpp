#include<iostream>
using namespace std;



int main(void) {
	char s[20]; cin >> s;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}