#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )
#define N (255)
#define vecvecInt vector<vector<int>>

int ans = 0;

vecvecInt Char2vecvecInt();
void shortest_route(vecvecInt p, int row, int col, int sum);


void shortest_route(vecvecInt p, int row, int col, int sum) 
{
	if (row >= p.size()) { return; }

	int val = p[row][col];
	if (ans < sum + val) { ans = sum + val; cout << row << " " << col << " " << sum << "+" <<  val << endl;}

	
	if ((row  + 1) < (p.size() / 2 + 1)) {
		shortest_route(p, row + 1, col, sum + val);
		shortest_route(p, row + 1, col + 1, sum + val);
	}
	else {
		if (col == 0) {
			shortest_route(p, row + 1, col, sum + val);
		}
		else if (col == p[row].size() - 1) {
			shortest_route(p, row + 1, col - 1, sum + val);
		}
		else {
			shortest_route(p, row + 1, col - 1, sum + val);
			shortest_route(p, row + 1, col, sum + val);
		}
	}
	
}

int main(void) 
{	
	vecvecInt p = Char2vecvecInt();
	shortest_route(p, 0, 0, 0);
	cout << ans << endl;
	return 0;
}

vecvecInt Char2vecvecInt() {
	vector<vector<int>> p;
	int cnt = 0;
	bool f = true;
	while (f) {
		char s[N];
		fgets(s, N, stdin);
		s[strlen(s) - 1] = '\0';
		char* ptr[N];
		int len = 0;
		ptr[0] = strtok(s, ",");
		for (int i = 1; ptr[i - 1] != NULL; i++) { ptr[i] = strtok(NULL, ","); len++; }

		vector<int> row;
		rep(i, len) { row.push_back(atoi(ptr[i])); }
		p.push_back(row);

		if (len == 1 && f) {
			cnt++;
			if (cnt == 2) { f = false; }
		}
	}
	return p;
}
