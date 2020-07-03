#include<iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

bool b[12][12];
int ans;

void print();

void vis(int a[][12], int i, int j) 
{	
	b[i][j] = true;
	if (0 <= j - 1 && a[i][j-1] == 1 && !b[i][j - 1]) vis(a, i, j - 1);
	if (j + 1 < 12 && a[i][j+1] == 1 && !b[i][j + 1]) vis(a, i, j + 1);
	if (0 <= i - 1 && a[i-1][j] == 1 && !b[i - 1][j]) vis(a, i - 1, j);
	if (i + 1 < 12 && a[i+1][j] == 1 && !b[i + 1][j]) vis(a, i + 1, j);

}

void NumberofIsland(int a[][12]) {
	rep(i, 12) {
		rep(j, 12) {
			if (a[i][j] == 1 && !b[i][j]) {
				vis(a, i, j);
				ans++;
				//print();
			}
		}
	}
}

int main(void)
{
	for (int z = 0; z < 3; z++) {
	    ans = 0;
		int a[12][12];
		rep(i, 12) { 
			char s[12 + 1]; cin >> s;
			rep(j, 12) { a[i][j] = s[j] - '0'; } 
		}
		rep(i, 12) { rep(j, 12) { b[i][j] = false; } }

		NumberofIsland(a);
		cout << ans << endl;
	}
	return 0;
}

void print()
{
	printf("-----------------------------\n");
	rep(i, 12) {
		rep(j, 12) {
			cout << b[i][j];
		}
		cout << endl;
	}
	printf("-----------------------------\n");
}