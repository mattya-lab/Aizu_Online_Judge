#include<iostream>
using namespace std;

char Figure(char S[][9]) 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (S[i][j] == '1' && S[i + 1][j] == '1' && S[i][j + 1] == '1' && S[i + 1][j + 1] == '1') return 'A';
			else if (S[i][j] == '1' && S[i][j + 1] == '1' && S[i][j + 2] == '1' && S[i][j + 3] == '1') return 'B';
			else if (S[i][j] == '1' && S[i + 1][j] == '1' && S[i + 2][j] == '1' && S[i + 3][j] == '1') return 'C';
			else if (S[i][j] == '1' && S[i + 1][j] == '1' && S[i + 1][j - 1] == '1' && S[i + 2][j - 1] == '1') return 'D';
			else if (S[i][j] == '1' && S[i][j + 1] == '1' && S[i + 1][j + 1] == '1' && S[i + 1][j + 2] == '1') return 'E';
			else if (S[i][j] == '1' && S[i + 1][j] == '1' && S[i + 1][j + 1] == '1' && S[i + 2][j + 1] == '1') return 'F';
			else if (S[i][j] == '1' && S[i + 1][j] == '1' && S[i][j + 1] == '1' && S[i + 1][j - 1] == '1') return 'G';
		}
	}
	return '\0';
}

int main(void) 
{
	for (int z = 0; z < 3; z++)
	{
		char S[8 + 1][8 + 1] = {};

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> S[i][j];
			}
		}
		cout << Figure(S) << endl;
	}
	return 0;
}