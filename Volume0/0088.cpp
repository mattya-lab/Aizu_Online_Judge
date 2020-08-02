#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define SIZE 255 

void Decode(char* s, char* t);
void Encode(char* t, char* u);

int main(void) {
	char s[SIZE] = ""; fgets(s, SIZE, stdin); s[strlen(s) - 1] = '\0';
	char t[SIZE] = "";
	char u[SIZE] = "";
	Decode(s, t);
	Encode(t, u);

	cout << u << endl;
	return 0;
}

void Decode(char* s, char* t)
{
	rep(i, strlen(s)) {
		switch (s[i]) {
		case ' ': strcat(t, "101"); break;
		//case ''': strcat(t, "000000"); break;
		case ',':  strcat(t, "000011"); break;
		case '.': strcat(t, "10010001"); break;
		case '?': strcat(t, "010001"); break;
		case 'A': strcat(t, "100101"); break;
		case 'B': strcat(t, "10011010"); break;
		case 'C': strcat(t, "0101"); break;
		case 'D': strcat(t, "0001"); break;
		case 'E': strcat(t, "110"); break;
		case 'F': strcat(t, "01001"); break;
		case 'G': strcat(t, "10011011"); break;
		case 'H': strcat(t, "010000"); break;
		case 'I': strcat(t, "0111"); break;
		case 'J': strcat(t, "10011000"); break;
		case 'K': strcat(t, "0110"); break;
		case 'L': strcat(t, "00100"); break;
		case 'M': strcat(t, "10011001"); break;
		case 'N': strcat(t, "10011110"); break;
		case 'O': strcat(t, "00101"); break;
		case 'P': strcat(t, "111"); break;
		case 'Q': strcat(t, "10011111"); break;
		case 'R': strcat(t, "1000"); break;
		case 'S': strcat(t, "00110"); break;
		case 'T': strcat(t, "00111"); break;
		case 'U': strcat(t, "10011100"); break;
		case 'V': strcat(t, "10011101"); break;
		case 'W': strcat(t, "000010"); break;
		case 'X': strcat(t, "10010010"); break;
		case 'Y': strcat(t, "10010011"); break;
		case 'Z': strcat(t, "10010000"); break;
		}
	}
}


void Encode(char* t, char* u)
{
	int i = 0, k = 0;
	char block[5] = "";
	rep(j, strlen(t)) {
		block[i] = t[j];
		i++;
		if (i % 5 == 0 || j + 1 == strlen(t)) {
			int val = strtol(block, NULL, 2);
			rep(l, 5) block[l] = '\0';
			switch (val) {
			case 0: u[k] = 'A'; break;
			case 1: u[k] = 'B'; break;
			case 2: u[k] = 'C'; break;
			case 3: u[k] = 'D'; break;
			case 4: u[k] = 'E'; break;
			case 5: u[k] = 'F'; break;
			case 6: u[k] = 'G'; break;
			case 7: u[k] = 'H'; break;
			case 8: u[k] = 'I'; break;
			case 9: u[k] = 'J'; break;
			case 10: u[k] = 'K'; break;
			case 11: u[k] = 'L'; break;
			case 12: u[k] = 'M'; break;
			case 13: u[k] = 'N'; break;
			case 14: u[k] = 'O'; break;
			case 15: u[k] = 'P'; break;
			case 16: u[k] = 'Q'; break;
			case 17: u[k] = 'R'; break;
			case 18: u[k] = 'S'; break;
			case 19: u[k] = 'T'; break;
			case 20: u[k] = 'U'; break;
			case 21: u[k] = 'V'; break;
			case 22: u[k] = 'W'; break;
			case 23: u[k] = 'X'; break;
			case 24: u[k] = 'Y'; break;
			case 25: u[k] = 'Z'; break;
			case 26: u[k] = ' '; break;
			case 27: u[k] = '.'; break;
			case 28: u[k] = ','; break;
			case 29: u[k] = '-'; break;
			case 30: strcat(u, "'"); break;
			case 31: u[k] = '?';  break;
			}
			k++;
			i = 0;
		}
	}
}