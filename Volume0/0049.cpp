#include<iostream>
using namespace std;

int main(void) {
	int n = 14;
	int num[4]; for (int i = 0; i < 4; i++) num[i] = 0;
	for (int i = 0; i < n; i++) {
		int a = 0;
		char b[2] = "";
		(void)scanf("%d,%s", &a, b);

		if (strcmp(b, "A") == 0) { num[0]++; }
		else if (strcmp(b, "B") == 0) { num[1]++; }
		else if (strcmp(b, "O") == 0) { num[3]++; }
		else if (strcmp(b, "AB") == 0) { num[2]++; }
	}

	for (int i = 0; i < 4; i++) { cout << num[i] << endl;  }
	return 0;
}