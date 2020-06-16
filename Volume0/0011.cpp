#include<iostream>
using namespace std;

#define N (128)
int main()
{
	int w, n; cin >> w >> n;
	int c[N];
	for (int i = 1; i <= w; i++) { c[i] = i; }

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int tmp = c[a];
		c[a] = c[b];
		c[b] = tmp;
	}

	for (int i = 1; i <= w; i++) { cout << c[i] << endl; }
	return 0;
}