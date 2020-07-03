#include<iostream>
#include<string.h>
using namespace std;

bool CheckSymmetry(char* word, int l, unsigned int r) {
	if(word[l] != word[r]) return false;
	return (l == r || l + 1 == r) ? true: CheckSymmetry(word, l + 1, r - 1);
}

int main(void) {

	int n = 4;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		char word[100 + 1] = ""; cin >> word;
		if (CheckSymmetry(word, 0, strlen(word) - 1)) ans++;
	}
	cout << ans << endl;
	return 0; 
}