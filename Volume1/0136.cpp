#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;
#define INF (999)

int main(void) 
{
	int n; cin >> n;
	vector<int> vh(6);
	rep(i, n) {
		double h; cin >> h;
		if (h < 165.0) { vh[0]++; }
		else if (165.0 <= h && h < 170.0) { vh[1]++; }
		else if (170.0 <= h && h < 175.0) { vh[2]++; }
		else if (175.0 <= h && h < 180.0) { vh[3]++; }
		else if (180.0 <= h && h < 185.0) { vh[4]++; }
		else { vh[5]++; }
	}
	rep(i, 6) {
		cout << i + 1 << ":";
		rep(j, vh[i]) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}