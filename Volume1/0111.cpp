#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define SIZE 200

void Decode(char* s, char* ds); 
bool EncodeList(char* t, char* es, int eslen);

void Encode(char* ds, char* es) {
	char t[SIZE] = "";
	int idx = 0;
	int dslen = 0, eslen = 0;
	while (ds[dslen] != '\0') {
		if (EncodeList(t, es, eslen)) {
			eslen++;
			strcpy(t, "");
			idx = 0;
		}
		else {
			t[idx] = ds[dslen];
			idx++;
			t[idx] = '\0';
			dslen++;
		}
	}
	es[eslen] = '\0';
}

int main(void) {
	char s[SIZE] = ""; cin >> s;
	char ds[SIZE] = "";
	Decode(s, ds);
	char es[SIZE] = ""; 
	Encode(ds, es);
	cout << es << endl;
	return 0;
}

bool  EncodeList(char* t, char* es, int eslen)
{
	bool f = false;

	if (strcmp(t, "101") == 0) { es[eslen] = ' '; f = true; }
	else if (strcmp(t, "110") == 0) { es[eslen] = 'E'; f = true; }
	else if (strcmp(t, "111") == 0) { es[eslen] = 'P'; f = true; }
	else if (strcmp(t, "0001") == 0) { es[eslen] = 'D'; f = true; }
	else if (strcmp(t, "0101") == 0) { es[eslen] = 'C'; f = true; }
	else if (strcmp(t, "0110") == 0) { es[eslen] = 'K'; f = true; }
	else if (strcmp(t, "0111") == 0) { es[eslen] = 'I'; f = true; }
	else if (strcmp(t, "1000") == 0) { es[eslen] = 'R'; f = true; }
	else if (strcmp(t, "00100") == 0) { es[eslen] = 'L'; f = true; }
	else if (strcmp(t, "00101") == 0) { es[eslen] = 'O'; f = true; }
	else if (strcmp(t, "00110") == 0) { es[eslen] = 'S'; f = true; }
	else if (strcmp(t, "00111") == 0) { es[eslen] = 'T'; f = true; }
	else if (strcmp(t, "01001") == 0) { es[eslen] = 'F'; f = true; }
	else if (strcmp(t, "000000") == 0) { es[eslen] = '\''; f = true; }
	else if (strcmp(t, "000001") == 0) { es[eslen] = '?'; f = true; }
	else if (strcmp(t, "000010") == 0) { es[eslen] = 'W'; f = true; }
	else if (strcmp(t, "000011") == 0) { es[eslen] = ','; f = true; }
	else if (strcmp(t, "010000") == 0) { es[eslen] = 'H'; f = true; }
	else if (strcmp(t, "010001") == 0) { es[eslen] = '.'; f = true; }
	else if (strcmp(t, "100101") == 0) { es[eslen] = 'A'; f = true; }
	else if (strcmp(t, "10010000") == 0) { es[eslen] = 'Z'; f = true; }
	else if (strcmp(t, "10010001") == 0) { es[eslen] = '-'; f = true; }
	else if (strcmp(t, "10010010") == 0) { es[eslen] = 'X'; f = true; }
	else if (strcmp(t, "10010011") == 0) { es[eslen] = 'Y'; f = true; }
	else if (strcmp(t, "10011000") == 0) { es[eslen] = 'J'; f = true; }
	else if (strcmp(t, "10011001") == 0) { es[eslen] = 'M'; f = true; }
	else if (strcmp(t, "10011010") == 0) { es[eslen] = 'B'; f = true; }
	else if (strcmp(t, "10011011") == 0) { es[eslen] = 'G'; f = true; }
	else if (strcmp(t, "10011100") == 0) { es[eslen] = 'U'; f = true; }
	else if (strcmp(t, "10011101") == 0) { es[eslen] = 'V'; f = true; }
	else if (strcmp(t, "10011110") == 0) { es[eslen] = 'N'; f = true; }
	else if (strcmp(t, "10011111") == 0) { es[eslen] = 'Q'; f = true; }

	return (f);
}

void Decode(char* s, char* ds) 
{
	rep(i, strlen(s)) {
		switch (s[i]) {
		case 'A': strcat(ds, "00000"); break;
		case 'B': strcat(ds, "00001"); break;
		case 'C': strcat(ds, "00010"); break;
		case 'D': strcat(ds, "00011"); break;
		case 'E': strcat(ds, "00100"); break;
		case 'F': strcat(ds, "00101"); break;
		case 'G': strcat(ds, "00110"); break;
		case 'H': strcat(ds, "00111"); break;
		case 'I': strcat(ds, "01000"); break;
		case 'J': strcat(ds, "01001"); break;
		case 'K': strcat(ds, "01010"); break;
		case 'L': strcat(ds, "01011"); break;
		case 'M': strcat(ds, "01100"); break;
		case 'N': strcat(ds, "01101"); break;
		case 'O': strcat(ds, "01110"); break;
		case 'P': strcat(ds, "01111"); break;
		case 'Q': strcat(ds, "10000"); break;
		case 'R': strcat(ds, "10001"); break;
		case 'S': strcat(ds, "10010"); break;
		case 'T': strcat(ds, "10011"); break;
		case 'U': strcat(ds, "10100"); break;
		case 'V': strcat(ds, "10101"); break;
		case 'W': strcat(ds, "10110"); break;
		case 'X': strcat(ds, "10111"); break;
		case 'Y': strcat(ds, "11000"); break;
		case 'Z': strcat(ds, "11001"); break;
		case ' ': strcat(ds, "11010"); break;
		case '.': strcat(ds, "11011"); break;
		case ',': strcat(ds, "11100"); break;
		case '-': strcat(ds, "11101"); break;
		case '\'': strcat(ds, "11110"); break;
		case '?': strcat(ds, "11111"); break;
		}
	}
	ds[strlen(ds)] = '\0';
}