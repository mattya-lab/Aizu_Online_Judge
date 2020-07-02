#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int Bottommost(int a, int b){
	return (a + b) % 10;
}

int main(void)
{
	rep(z, 3) {
		char s[10 + 1]; cin >> s;
		vector<vector<int>> a(10); 
		rep(i, 10) { a[0].push_back(s[i] - '0'); }

		for (int i = 1; i < a[0].size(); i++) {
			for (int j = 0; j < a[i - 1].size()- 1; j++) {
				a[i].push_back(Bottommost(a[i - 1][j], a[i - 1][j + 1]));
			}
		}
		cout << a[a.size() - 1][0] << endl;
	}
	return 0;
}
