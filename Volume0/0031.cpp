#include<iostream>
using namespace std;

int main(void) 
{
	for (int l = 0; l < 3; l++) {
		int n;  cin >> n;
		bool vis[10 + 1]; for (int i = 0; i <= 9; i++) vis[i] = false;

		for(int k = 0; k < 10; k++){
			if (n % 2 == 1) { vis[k] = true; }
			n = n / 2;
		}
		int k = 1;
		for (int i = 0; i <= 9; i++) {
			if (vis[i]) { printf("%d ", k); }
			k *= 2;
		}
		printf("\n");
	}
	return 0;
}