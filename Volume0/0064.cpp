#include<iostream>
#include<string.h>
using namespace std;

int getValue(char* word, char* num, unsigned int k, int *skip) {
	if ('0' <= word[k] && word[k] <= '9') {
		num[*skip] = word[k];
		*(skip) = *(skip)+1;
		getValue(word, num, k + 1, skip);
	}
	else { return atoi(num); }
}

int main(void) 
{
	int n = 2;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		char word[100 + 1] = ""; cin >> word;
		for (unsigned int k = 0; k < strlen(word - 1); k++) {
			char num[100 + 1] = "0";
			int skip = 0;
			sum += getValue(word, num, k, &skip);
			k += skip;			
		}
	}
	cout << sum << endl;
	return 0; 
}